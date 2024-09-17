/**
 * @file lab1.cpp
 * @author Trevor Ruttan
 * @Date   9/17/2017
 * @version 1.0
 * @section DESCRIPTION
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

#include <format>

using namespace std;

/*
 * SPECIFICATIONS
 * Read the grades.csv.
 * Calculate the average exam grades.
 * Display the original data and the average exam grades in tabular format.
 * csv is formatted as follows: firstname,lastname,exam1grade,exam2grade,exam3grade,average
 * additionally output the calculated data into averagegrades.csv
 */

// define a struct to hold student data
struct Student {
  std::string firstName;
  std::string lastName;
  int exam1;
  int exam2;
  int exam3;
  double average;
  void display() {
    std::cout << std::left << std::setw(12) << firstName << std::setw(12) << lastName << std::setw(10) << exam1 << std::setw(10) << exam2 << std::setw(10) << exam3 << std::setw(10) << std::fixed << std::setprecision(2) << average << std::endl;
  }
  void toFile(std::ofstream & file) {
	file << std::left << std::setw(12) << firstName << std::setw(12) << lastName << std::setw(10) << exam1 << std::setw(10) << exam2 << std::setw(10) << exam3 << std::setw(10) << std::fixed << std::setprecision(2) << average << std::endl;
  }
};

// define a vector of student structs
std::vector < Student > students;

int main() {
  std::cout << std::left << std::setw(24) << "Name" << std::setw(10) << "Exam1" << std::setw(10) << "Exam2" << std::setw(10) << "Exam3" << std::setw(10) << "Avg" << std::endl;
  std::cout << "-------------------------------------------------------------" << std::endl;

  std::ifstream grades("grades.csv");
  if (!grades) {
    std::cerr << "Failed to open file 'grades.csv'" << std::endl;
    return 1;
  }

  std::string line;
  std::getline(grades, line);
  while (std::getline(grades, line)) {
    std::istringstream iss(line);
    Student student;
    std::string exam1, exam2, exam3;
	std::getline(iss, student.firstName, ',');
	std::getline(iss, student.lastName, ',');
	std::getline(iss, exam1, ',');
	std::getline(iss, exam2, ',');
	std::getline(iss, exam3, ',');

    student.exam1 = std::stoi(exam1);
    student.exam2 = std::stoi(exam2);
    student.exam3 = std::stoi(exam3);

    student.average = (student.exam1 + student.exam2 + student.exam3) / 3.0;
    students.push_back(student);
  }

  for (auto & student: students) {
    student.display();
  }

  std::ofstream averageGrades("averagegrades.csv");

  averageGrades << std::left << std::setw(24) << "Name" << std::setw(10) << "Exam1" << std::setw(10) << "Exam2" << std::setw(10) << "Exam3" << std::setw(10) << "Avg" << std::endl;
  averageGrades << "-------------------------------------------------------------" << std::endl;

  for (auto & student: students) {
	student.toFile(averageGrades);
  }

  return 0;
}