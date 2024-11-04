/**
 * @file Grading.h
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

#include "Student.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Grading {
private:
  unordered_map<string, Student> students;
  int numAssignments;
  int maxScorePerAssignment;

public:
  Grading();

  void addStudent(string name, vector<int> grades);

void printStudents();
}
;