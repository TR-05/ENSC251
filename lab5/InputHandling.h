/**
 * @file InputHandling.h
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

#pragma once
#include "TimeFormatMistake.h"
#include <iostream>

/**
 * @brief Continuously prompts the user to enter a time in 24-hour notation and
 * checks its validity.
 */
void pollInput();

/**
 * @brief Checks if the input time is valid and converts it to 12-hour notation.
 *
 * @param input The input time in 24-hour notation.
 * @return true if the input time is valid, false otherwise.
 */
bool checkInputTime(string input);

pair<int, int> validateInput(string input);