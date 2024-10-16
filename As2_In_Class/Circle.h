/**
 * @file Circle.h
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

#pragma once
#include "Shape.h"

class Circle : public Shape 
{
    public:
    Circle();
    Circle(int radius);
    void setRadius(int newRadius);
    double getRadius();
    virtual double getArea();
    private:
    int radius;
};