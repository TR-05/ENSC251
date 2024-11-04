/**
 * @file Book.cpp
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

#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    year = "";
}

Book::Book(string title, string author, string year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getYear() {
    return year;
}

bool Book::operator<(const Book &other) const {
    return author < other.author;
}