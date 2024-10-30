/**
 * @file InputHandling.cpp
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

#include "InputHandling.h"

/**
 * @brief Continuously prompts the user to enter a time in 24-hour notation and
 * checks its validity.
 */
void pollInput() {
  char continueInput = 'y';
  string timeInput = "";
  while (true) {
    cout << "Enter time in 24-hour notation:\n";
    getline(cin, timeInput);
    if (!checkInputTime(timeInput)) {
      cout << "Try again:\n";
      continue;
    }

    cout << "Again?(y/n) \n";
    cin >> continueInput;
    cin.ignore(numeric_limits<streamsize>::max(),
               '\n'); // clear the buffer up to the most recent \n
    if (continueInput != 'y' && continueInput != 'Y') {
      cout << "End of program\n";
      break;
    }
  }
}

/**
 * @brief Checks if the input time is valid and converts it to 12-hour notation.
 *
 * @param input The input time in 24-hour notation.
 * @return true if the input time is valid, false otherwise.
 */
bool checkInputTime(string input) {
  bool success = false;
  pair<int, int> time = validateInput(input);
  if (time.first != -1) {
    success = true;
  } else {
    return false;
  }
  bool isPM = false;
  if (time.first > 12) {
    time.first -= 12;
    isPM = true;
  }

  cout << "That is the same as\n";
  cout << time.first << ":";
  if (time.second < 10) {
    cout << "0";
  }
  cout << time.second << " ";

  if (isPM) {
    cout << "PM\n";
  } else {
    cout << "AM\n";
  }
  return success;
}

/**
 * @brief validates that the input string follows the format of 24-hour time (ie
 * 10:42).
 *
 * @param input
 * @return pair<int, int>
 */
pair<int, int> validateInput(string input) {
  try {
    if (input.size() > 5) {
      throw TimeFormatMistake(input.c_str());
    }
    if (input.size() == 4) {
      string modifiedInput = " " + input;
      input = modifiedInput;
    }

    size_t colonPos = input.find_first_of(":");
    if (colonPos != 2) {
      throw TimeFormatMistake(input.c_str());
    }

    int hours, minutes;
    try {
      hours = stoi(input.substr(0, colonPos));
      minutes = stoi(input.substr(colonPos + 1, 2));
    } catch (const std::invalid_argument &) {
      throw TimeFormatMistake(input.c_str());
    }

    if (hours < 0 or hours > 23 or minutes < 0 or minutes > 59) {
      throw TimeFormatMistake(input.c_str());
    }
    return (make_pair(hours, minutes));
  } catch (TimeFormatMistake tfm) {
    cout << tfm.what();
  }
  return (make_pair(-1, -1));
}
