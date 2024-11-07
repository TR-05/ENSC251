/**
 * @file Student.h
 * @author Trevor Ruttan
 * @Date 11/7/2024
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
#include <string>
#include <vector>

using namespace std;

/**
 * @class Student
 * @brief A class to represent a student with a name and grades.
 */
class Student {
private:
  string name;        ///< The name of the student.
  vector<int> grades; ///< The grades of the student.

public:
  /**
   * @brief Default constructor for the Student class.
   */
  Student() : name(""), grades(vector<int>(1, 0)) {}

  /**
   * @brief Parameterized constructor for the Student class.
   * @param name The name of the student.
   * @param grades The grades of the student.
   */
  Student(string name, vector<int> grades) : name(name), grades(grades) {}

  /**
   * @brief Gets the name of the student.
   * @return The name of the student.
   */
  string getName() const { return name; }

  /**
   * @brief Sets the name of the student.
   * @param name The new name of the student.
   */
  void setName(string name) { this->name = name; }

  /**
   * @brief Sets the grades of the student.
   * @param grades The new grades of the student.
   */
  void setGrades(vector<int> grades) { this->grades = grades; }

  /**
   * @brief Gets the grades of the student.
   * @return The grades of the student.
   */
  vector<int> getGrades() const { return grades; }
};