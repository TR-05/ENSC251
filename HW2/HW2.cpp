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
i. An exception should be raised if the number of assignments is less than 0.
ii. An exception should be raised if any assignment score is less than 0.
iii. An exception should be raised if the any of the assignments score exceeds 100.
iv. An exception should be raised if scores are entered for a student whose name has already
been recorded in the program.
v. An exception should be raised if any score is below 0 or higher than the maximum score
for a given assignment.
*/

int main() {
  // type -1 when prompted for # of assignments to trigger exception 1
  // type -1 when prompted for assignment score to trigger exception 2
  // type 101 when prompted for assignment score to trigger exception 3
  // enter the same name (first and last) twice to trigger exception 4
  // exception 5 is impossible as exception 2 and 3 cover this case

  interface();

  return 0;
}