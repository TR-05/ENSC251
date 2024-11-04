/**
 * @file Book.h
 * @author Trevor Ruttan
 * @Date 11/4/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____11/4/2024______________
//
// ____ 301580889 ______
//

#pragma once 

#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string title;
        string author;
        string year;
    public:
        Book();
        Book(string title, string author, string year);
        string getTitle();
        string getAuthor();
        string getYear();
        bool operator<(const Book &other) const;
};  