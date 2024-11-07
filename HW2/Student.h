/**
 * @file Student.h
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

#include <string>
#include <vector>

using namespace std;

class Student {
private:
  string name;
  vector<int> grades;

public:
  Student() : name(""), grades(vector<int>(1, 0)) {}
  Student(string name, vector<int> grades) : name(name), grades(grades) {}

  string getName() const { return name; }
  void setName(string name) { this->name = name; }
  void setGrades(vector<int> grades) { this->grades = grades; }

  vector<int> getGrades() const { return grades; }
};