/**
 * @file lab1.cpp
 * @author Trevor Ruttan
 * @Date   9/17/2024
 * @version 1.0
 * @section DESCRIPTION
 * This program reads a csv file containing student grades and calculates the average of the grades.
 */

// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Ruttan ____      _____9/17/2024______________
//
// ____ 301580889 ______

#include <iostream>

#include <iomanip>

#include <fstream>

#include <vector>

#include <sstream>

using namespace std;

/**
 * @brief Student struct holds all data for 1 student and methods to print the data
 */
struct Student {
  string name;
  int exam1;
  int exam2;
  int exam3;
  float average;

  /**
   * @brief Prints the student data to the terminal with proper formatting
   * @return void
   **/
  void printToTerminal() {
    cout << left << setw(24) << name;
    cout << setw(10) << exam1;
    cout << setw(10) << exam2;
    cout << setw(10) << exam3;
    cout << setw(10) << fixed << setprecision(2) << average << endl;
  }

  /**
   * @brief Prints the student data to a file with proper formatting
   * @param file the file to write to
   * @return void
   **/
  void printToFile(ofstream & file) {
    file << left << setw(24) << name;
    file << setw(10) << exam1;
    file << setw(10) << exam2;
    file << setw(10) << exam3;
    file << setw(10) << fixed << setprecision(2) << average << endl;
  }
};

vector < Student > students;


/**
 * @brief Opens the grades.csv file and reads the data into the students vector
 */
void collectData() {
  // Open the file for reading
  ifstream grades("grades.csv");
  // Read the header line and discard it
  string line;
  getline(grades, line);

  // loop through the file and read the data into the students vector
  while (getline(grades, line)) {
    // Use a string stream to read the data from the file
    istringstream iss(line);
    Student student;
    string temp;
    //use a temporary string to read the name data then concatenate the first and last name
    getline(iss, student.name, ',');
    getline(iss, temp, ',');
    student.name += " " + temp;
    //use a temporary string to read the exam data then convert it to int
    getline(iss, temp, ',');
    student.exam1 = stoi(temp);
    getline(iss, temp, ',');
    student.exam2 = stoi(temp);
    getline(iss, temp, ',');
    student.exam3 = stoi(temp);

    student.average = (student.exam1 + student.exam2 + student.exam3) / 3.0;
    students.push_back(student);
  }
  grades.close();
  // Print the collected data to the terminal
}

int main() {
  // Vector to hold all students
  collectData();
  // Print the header
  cout << left 
  << setw(24) << "Name" 
  << setw(10) << "Exam1" 
  << setw(10) << "Exam2" 
  << setw(10) << "Exam3" 
  << setw(10) << "Avg" << endl;
  cout << "-----------------------------------------------------------" << endl;
  // loop through the students vector and print all the collected data
  for (auto & student: students) {
    student.printToTerminal();
  }

  // Create and open a new csv file to write the data to
  ofstream averageGrades("averagegrades.csv");
  // Print the header to the file
  averageGrades << left
   << setw(24) << "Name" 
   << setw(10) << "Exam1" 
   << setw(10) << "Exam2" 
   << setw(10) << "Exam3" 
   << setw(10) << "Avg" << endl;
  averageGrades << "-----------------------------------------------------------" << endl;
  // Print the collected data to the file
  for (auto & student: students) {
    student.printToFile(averageGrades);
  }
  averageGrades.close();

  return 0;
}