/**
 * @file Interface.cpp
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

#include "Interface.h"
#include "Book.h"
#include <iostream>

using namespace std;

vector<Book> books;

void printMenu() {
  cout << "Select from the following choices:" << endl;
  cout << "1. Add new book" << endl;
  cout << "2. Print listing sorted by author" << endl;
  cout << "3. Quit" << endl;
}

void addNewBook() {
  string title;
  string author;
  string year;
  cout << "Enter title:";
  cin.ignore();
  getline(cin, title);
  cout << "Enter author:";
  getline(cin, author);
  cout << "Enter date:";
  getline(cin, year);
  Book newBook(title, author, year);
  books.push_back(newBook);
}

void PrintSorted() {
  cout << "The books entered so far, sorted alphabetically by author are:"
       << endl;

  sort(books.begin(), books.end());
  for (Book book : books) {

    cout << "   " << book.getAuthor() << ". " << book.getTitle() << ". "
         << book.getYear() << "." << endl;
  }
}
bool select() {
    bool quit = false;
  int choice;
  cin >> choice;
  switch (choice) {
  case 1:
    addNewBook();
    return 0;
    break;
  case 2:
    PrintSorted();
    return 0;
    break;
  case 3:
    return 1;
    break;
  default:
    cout << "Invalid selection" << endl;
    return 1;
    break;
  }
}

void interfaceLoop() {
  while (true) {
    printMenu();
    if (select() == true) {
      break;
    }
  }
}
