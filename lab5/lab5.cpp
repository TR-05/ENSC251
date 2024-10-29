/**
 * @file lab5.cpp
 * @author Trevor Ruttan
 * @Date 10/29/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____10/29/2024______________
//
// ____ 301580889 ______
//

#include "TimeFormatMistake.h"
#include <iostream>
#include <string_view>

using namespace std;

bool checkInputTime(string input) {
  bool inputError = false;
  string_view inputView = input;
  if (inputView.size() > 8) {
    inputError = true;
  }
  if (inputView.size() == 7) {
    //inputView.;
  }

  size_t colonPos = inputView.find_first_of(":");
  if (colonPos == string::npos or colonPos == 0 or colonPos > 2) {
    inputError = true;
  }


  if (inputError) {
    try {
      string output = "There is no such time as " + input;
      cout << output << endl;
      throw TimeFormatMistake(output.c_str());
    } catch (TimeFormatMistake tfm) {
      cout << tfm.what();
    }
  }
  return inputError;
}

void pollInput() {
  char continueInput = 'y';
  string timeInput = "";
  while (true) {
    cout << "Enter time in 24-hour notation:\n";
    cin >> timeInput;
    if (checkInputTime(timeInput) ) {
      cout << "Try again:\n";
      continue;
    }

    cout << "Again?(y/n) \n";
    cin >> continueInput;
    if (continueInput != 'y' and continueInput != 'Y') {
      cout << "End of program\n";
      break;
    }
  }
}

int main() { pollInput(); }