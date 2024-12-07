#include "../include/cubicBezier.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace tntnlib;

Path Path::operator+=(const Path &other) {
  int startTime = 0;
  int newNumberOfPoints = this->numberOfPoints + other.numberOfPoints;
  x.resize(newNumberOfPoints);
  y.resize(newNumberOfPoints);
  theta.resize(newNumberOfPoints);
  curvature.resize(newNumberOfPoints);
  lengthAtT.resize(newNumberOfPoints);
  d1x.resize(newNumberOfPoints);
  d1y.resize(newNumberOfPoints);
  d2x.resize(newNumberOfPoints);
  d2y.resize(newNumberOfPoints);
  for (int i = 0; i < other.numberOfPoints; i++) {
    this->x[this->numberOfPoints + i] = other.x[i];
    this->y[this->numberOfPoints + i] = other.y[i];
    this->theta[this->numberOfPoints + i] = other.theta[i];
    this->d1x[this->numberOfPoints + i] = other.d1x[i];
    this->d1y[this->numberOfPoints + i] = other.d1y[i];
    this->d2x[this->numberOfPoints + i] = other.d2x[i];
    this->d2y[this->numberOfPoints + i] = other.d2y[i];
    this->curvature[this->numberOfPoints + i] = other.curvature[i];
    this->lengthAtT[this->numberOfPoints + i] =
        this->length + other.lengthAtT[i];
  }
  this->x3 = other.x3;
  this->y3 = other.y3;
  this->genTime = 0;
  this->length += other.length;
  this->numberOfPoints = newNumberOfPoints;
  return Path(*this);
}

float Path::xAt(float t) {
  return ((c1x * t * t * t) + (c2x * t * t) + (c3x * t) + x0);
}

float Path::yAt(float t) {
  return ((c1y * t * t * t) + (c2y * t * t) + (c3y * t) + y0);
}

float Path::d1xAt(float t) { return (3 * c1x * t * t) + (2 * c2x * t) + c3x; }

float Path::d1yAt(float t) { return (3 * c1y * t * t) + (2 * c2y * t) + c3y; }

float Path::d2xAt(float t) { return (6 * c1x * t) + (2 * c2x); }

float Path::d2yAt(float t) { return (6 * c1y * t) + (2 * c2y); }

void Path::generatePath() {
  int startTime = 0;
  float newt = 0;
  float D1X, D1Y;
  numberOfPoints = 1;
  while (newt < 1) {
    D1X = d1xAt(newt);
    D1Y = d1yAt(newt);
    newt += pointSpacing / sqrt(D1X * D1X + D1Y * D1Y);
    t.push_back(newt);
    numberOfPoints++;
  }
  x.resize(numberOfPoints);
  y.resize(numberOfPoints);
  theta.resize(numberOfPoints);
  curvature.resize(numberOfPoints);
  lengthAtT.resize(numberOfPoints);
  d1x.resize(numberOfPoints);
  d1y.resize(numberOfPoints);
  d2x.resize(numberOfPoints);
  d2y.resize(numberOfPoints);

  float t = 0;
  const float radToDeg = 180 / M_PI;
  for (size_t i = 0; i < x.size(); i++) {
    t = this->t[i];
    if (t > 1)
      t = 1;
    this->x[i] = xAt(t);
    this->y[i] = yAt(t);
    this->d1x[i] = d1xAt(t);
    this->d1y[i] = d1yAt(t);
    this->d2x[i] = d2xAt(t);
    this->d2y[i] = d2yAt(t);
    this->theta[i] = 90 - atan2(this->d1y[i], this->d1x[i]) * radToDeg;
    this->length += pointSpacing;
    this->lengthAtT[i] = this->length;
    double denominator = d1x[i] * d1x[i] + d1y[i] * d1y[i];
    this->curvature[i] = -1 * (d1x[i] * d2y[i] - d1y[i] * d2x[i]) /
                         sqrt(denominator * denominator * denominator);
  }
  this->genTime = 0;
}

void Path::printPath() {

  printf("\n\nGiven Points: \n");
  printf("(%.2f, %.2f),(%.2f, %.2f),(%.2f, %.2f),(%.2f, %.2f),\n", x0, y0, x1,
         y1, x2, y2, x3, y3);
  std::cout << "\n" << std::flush;

  int p = 0;
  for (size_t i = 0; i < (x.size()); i++) {
    printf("(%.2f, %.2f),", this->x[i], this->y[i]);
    if (p > 3) {
      p = 0;
      printf("\n");
      std::cout << std::flush;
    }
    p++;
    std::cout << std::flush;
  }

  printf("\n");
  printf("curve Length: %.2f", this->length);
  printf("\n\n(%.2f, %.2f),", x.back(), y.back());
  std::cout << "\n" << std::flush;
}

void Path::savePath() {
    
  std::ofstream outFile("path_output.txt");
  for (size_t i = 0; i < x.size(); i++) {
    outFile << this->x[i] << "," << this->y[i] << "\n";
  }
  outFile.close();
}