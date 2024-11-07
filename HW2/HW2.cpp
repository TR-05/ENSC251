/**
 * @file HW2.cpp
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

#include "Interface.h"

/*
• An exception should be raised if the number of assignments is less than 0.
• An exception should be raised if any assignment score is less than 0.
• An exception should be raised if the total scores for the assignments exceeds maximum
allowed score for each assignment x number of assignments.
• An exception should be raised if grades are entered for a student whose name has already
been recorded in the program.
• An exception should be raised if any score is below 0 or exceeds the maximum allowed
score for a given assignment.
*/

int main() {
  // type -1 when prompted for # of assignments to trigger exception 1
  // exception 3 is not triggerable through user input as exception 5 will be triggered first
  // input any student then input a second with the same name to trigger exception 4
  // type 101 when prompted for assignment score to trigger exception 5

  interface();

  return 0;
}