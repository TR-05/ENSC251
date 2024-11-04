/**
 * @file Grading.cpp
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

#include "Grading.h"

Grading::Grading() : numAssignments(0), maxScorePerAssignment(0) {
  try {
    cout << "Enter number of assignments: ";
    cin >> numAssignments;
    if (numAssignments < 0) {
      throw invalid_argument("Number of assignments cannot be less than 0.");
    }
    cout << "Enter maximum score per assignment: ";
    cin >> maxScorePerAssignment;

    while (true) {
      string name;
      vector<int> grades(numAssignments);

      cout << "Enter student name (or 'exit' to finish): ";
      cin.ignore();
      getline(cin, name);
      if (name == "exit")
        break;

      cout << "Enter grades for " << numAssignments << " assignments: ";
      for (int i = 0; i < numAssignments; ++i) {
        cin >> grades[i];
      }

      this->addStudent(name, grades);
    }

    this->printStudents();
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }
}

void Grading::addStudent(string name, vector<int> grades) {
  if (students.find(name) != students.end()) {
    throw invalid_argument("Student name already recorded.");
  }
  if (grades.size() != numAssignments) {
    throw invalid_argument(
        "Number of grades does not match number of assignments.");
  }
  int totalScore = 0;
  for (int grade : grades) {
    if (grade < 0 || grade > maxScorePerAssignment) {
      throw invalid_argument("Invalid grade value.");
    }
    totalScore += grade;
  }
  if (totalScore > maxScorePerAssignment * numAssignments) {
    throw invalid_argument("Total score exceeds maximum allowed score.");
  }
  students[name] = Student(name, grades);
}

void Grading::printStudents() {
  for (const auto &pair : students) {
    cout << "Student: " << pair.second.getName() << ", Grades: ";
    for (int grade : pair.second.getGrades()) {
      cout << grade << " ";
    }
    cout << endl;
  }
}