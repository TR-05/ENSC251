/**
 * @file lab1.cpp
 * @author Trevor Ruttan
 * @Date   9/17/2017
 * @version 1.0
 * @section DESCRIPTION
 *
 * This program reads a csv file containing student grades and calculates the average of the grades.
 */

// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Ruttan ____      _____9/17/2017______________
//
// ____ 301580889 ______

#include <iostream>

#include <iomanip>

#include <fstream>

#include <vector>

#include <sstream>

/*
 * SPECIFICATIONS
 * Read the grades.csv.
 * Calculate the average exam grades.
 * Display the original data and the average exam grades in tabular format.
 * csv is formatted as follows: firstname,lastname,exam1grade,exam2grade,exam3grade,average
 * additionally output the calculated data into averagegrades.csv
 */

/**
 * @brief Student struct holds all data for 1 student and methods to print the data
 */
struct Student {
  std::string name;
  int exam1;
  int exam2;
  int exam3;
  float average;

  /**
   * @brief Prints the student data to the terminal with proper formatting
   * @return void
   **/
  void printToTerminal() {
    std::cout << std::left << std::setw(24) << name;
    std::cout << std::setw(10) << exam1;
    std::cout << std::setw(10) << exam2;
    std::cout << std::setw(10) << exam3;
    std::cout << std::setw(10) << std::fixed << std::setprecision(2) << average << std::endl;
  }

  /**
   * @brief Prints the student data to a file with proper formatting
   * @param file the file to write to
   * @return void
   **/
  void printToFile(std::ofstream & file) {
    file << std::left << std::setw(24) << name;
    file << std::setw(10) << exam1;
    file << std::setw(10) << exam2;
    file << std::setw(10) << exam3;
    file << std::setw(10) << std::fixed << std::setprecision(2) << average << std::endl;
  }
};

// Vector to hold all students
std::vector < Student > students;

int main() {
  // Print the header
  std::cout << std::left << std::setw(24) << "Name" << std::setw(10) << "Exam1" << std::setw(10) << "Exam2" << std::setw(10) << "Exam3" << std::setw(10) << "Avg" << std::endl;
  std::cout << "-----------------------------------------------------------" << std::endl;
  // Open the file for reading
  std::ifstream grades("grades.csv");
  // Read the first line and discard it
  std::string line;
  std::getline(grades, line);

  // loop through the file and read the data into the students vector
  while (std::getline(grades, line)) {
    std::istringstream iss(line);
    Student student;
    std::string exam1, exam2, exam3;
    std::string temp;
    std::getline(iss, student.name, ',');
    std::getline(iss, temp, ',');
    student.name += " ";
    student.name += temp;
    std::getline(iss, exam1, ',');
    std::getline(iss, exam2, ',');
    std::getline(iss, exam3, ',');

    student.exam1 = std::stoi(exam1);
    student.exam2 = std::stoi(exam2);
    student.exam3 = std::stoi(exam3);

    student.average = (student.exam1 + student.exam2 + student.exam3) / 3.0;
    students.push_back(student);
  }
  grades.close();
  // Print the collected data to the terminal
  for (auto & student: students) {
    student.printToTerminal();
  }

  // Create and open a new csv file to write the data to
  std::ofstream averageGrades("averagegrades.csv");
  // Print the header to the file
  averageGrades << std::left << std::setw(24) << "Name" << std::setw(10) << "Exam1" << std::setw(10) << "Exam2" << std::setw(10) << "Exam3" << std::setw(10) << "Avg" << std::endl;
  averageGrades << "-----------------------------------------------------------" << std::endl;
  // Print the collected data to the file
  for (auto & student: students) {
    student.printToFile(averageGrades);
  }
  averageGrades.close();

  return 0;
}