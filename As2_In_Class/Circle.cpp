/**
 * @file Circle.cpp
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

#include "Circle.h"

Circle::Circle()
: Shape("Circle"), radius(0)
{}

Circle::Circle(int radius)
: Shape("Circle"), radius(radius)
{}

void Circle::setRadius(int newRadius)
{
    this->radius = newRadius;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::getArea()
{
    return 3.14159 * radius * radius;
}