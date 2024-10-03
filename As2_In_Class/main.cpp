/**
 * @file main.cpp
 * @author Trevor Ruttan, Rohin Gill
 * @Date 10/3/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan, Rohin Gill ____ _____10/3/2024______________
//
// ____ 301580889, 301582525______
//

#include <iostream>
#include <iomanip>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

int main() {
  Circle c(2);
  cout << c.getName() << " has radius " << c.getRadius() << " and area "
       << c.getArea() << endl;

  Rectangle r(3, 4);
  cout << r.getName() << " has width " << r.getWidth() << " has height "
       << r.getHeight() << " and area " << std::fixed << std::setprecision(1) << r.getArea() << endl;

  return 0;
}