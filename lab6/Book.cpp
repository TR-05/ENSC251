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
#include <cctype>

/**
 * @brief Default constructor for the Book class.
 * Initializes the title, author, and year to empty strings.
 */
Book::Book() {
  title = "";
  author = "";
  year = "";
}

/**
 * @brief Parameterized constructor for the Book class.
 *
 * @param title The title of the book.
 * @param author The author of the book.
 * @param year The publication year of the book.
 */
Book::Book(string title, string author, string year)
    : title(title), author(author), year(year) {}

/**
 * @brief Gets the title of the book.
 *
 * @return The title of the book.
 */
string Book::getTitle() { return title; }

/**
 * @brief Gets the author of the book.
 *
 * @return The author of the book.
 */
string Book::getAuthor() { return author; }

/**
 * @brief Gets the publication year of the book.
 *
 * @return The publication year of the book.
 */
string Book::getYear() { return year; }

/**
 * @brief Overloads the less-than operator to compare books by author.
 *
 * @param other The other book to compare with.
 * @return true if the author of this book is lexicographically less than the
 * author of the other book.
 * @return false otherwise.
 */
bool Book::operator<(const Book &other) const {
  string upperAuthor;
  for (char ch : author) {
    upperAuthor += toupper(ch);
  }
  string upperOtherAuthor;
  for (char ch : other.author) {
    upperOtherAuthor += toupper(ch);
  }
  return upperAuthor < upperOtherAuthor;
}