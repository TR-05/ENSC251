/**
 * @file Interface.cpp
 * @author Trevor Ruttan
 * @Date 11/8/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____11/8/2024______________
//
// ____ 301580889 ______
//

#include "Student.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Prompts the user to enter the number of assignments.
 * @throws invalid_argument if the number of assignments is less than 0.
 */
void enterNumAssignments();

/**
 * @brief Prompts the user to enter a student's name.
 * @throws invalid_argument if the student name is already recorded.
 */
void enterStudentName();

/**
 * @brief Prompts the user to enter a student's scores.
 * @throws invalid_argument if any score is invalid or the total score exceeds the maximum allowed score.
 */
void enterStudentScores();

/**
 * @brief Checks if the user wants to add another student.
 */
void checkIfDone();

/**
 * @brief Enumeration for the different steps in the interface.
 */
enum STEP {
  promptNumAssignments,
  promptStudentName,
  promptStudentScores,
  promptFinished,
} step;

int numAssignments = 0;
unordered_map<string, Student> students;
string currentStudent = "";
bool finished = false;

/**
 * @brief Main interface function that handles the different steps and loops.
 */
void interface() {
  while (!finished) {
    switch (step) {
    case promptNumAssignments:
      enterNumAssignments();
      break;
    case promptStudentName:
      enterStudentName();
      break;
    case promptStudentScores:
      enterStudentScores();
      break;
    case promptFinished:
      checkIfDone();
      break;
    default:
      break;
    }
  }

  for (const auto &pair : students) {
    cout << "Student: " << pair.second.getName() << ", Grades: ";
    for (int grade : pair.second.getGrades()) {
      cout << grade << " ";
    }
    cout << endl;
  }
}

/**
 * @brief Prompts the user to enter the number of assignments.
 * @throws invalid_argument if the number of assignments is less than 0.
 */
void enterNumAssignments() {
  try {
    int newNumAssignments = 0;
    cout << "Enter number of assignments: ";
    cin >> newNumAssignments;
    if (newNumAssignments < 0) {
      throw invalid_argument("Number of assignments cannot be less than 0.");
    } else {
      numAssignments = newNumAssignments;
      step = promptStudentName;
    }
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
    cout << "Try Again: " << endl;
  }
}

/**
 * @brief Prompts the user to enter a student's name.
 * @throws invalid_argument if the student name is already recorded.
 */
void enterStudentName() {

  try {
    string name;
    cout << "Enter student first name: " << endl;
    cin >> name;
    string lastName;
    cout << "Enter student last name: " << endl;
    cin >> lastName;
    name += " " + lastName;
    if (students.find(name) != students.end()) {
      throw invalid_argument("Student name already recorded.");
    } else {
      Student newStudent;
      newStudent.setName(name);
      students[name] = newStudent;
      step = promptStudentScores;
      currentStudent = name;
    }
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
    cout << "Try Again: " << endl;
  }
}

/**
 * @brief Prompts the user to enter a student's scores.
 * @throws invalid_argument if any score is invalid or the total score exceeds the maximum allowed score.
 */
void enterStudentScores() {
  try {
    vector<int> grades(numAssignments, 0);
    int totalScore = 0;
    cout << "Enter Scores For " << currentStudent << endl;
    for (int i = 0; i < numAssignments; ++i) {
      cout << "Assignment " << i + 1 << " Score: ";
      cin >> grades[i];
      if (grades[i] < 0 or grades[i] > 100) {
        throw invalid_argument("Invalid grade value.");
      }
      totalScore += grades[i];
    }
    if (grades.size() != numAssignments) {
      throw invalid_argument(
          "Number of grades does not match number of assignments.");
    }

    int maxCourseScore = numAssignments * 100;
    if (totalScore > maxCourseScore) {
      throw invalid_argument("Total score exceeds maximum allowed score.");
    }
    students[currentStudent].setGrades(grades);
    step = promptFinished;
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
    cout << "Try Again: " << endl;
  }
}

/**
 * @brief Checks if the user wants to add another student.
 */
void checkIfDone() {
  cout << "Add Another Student? (y/n): " << endl;
  char c = ' ';
  cin >> c;
  if (c != 'Y' and c != 'y') {
    finished = true;
  } else {
    step = promptStudentName;
  }
}