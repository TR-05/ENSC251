/**
 * @file main.cpp
 * @author Trevor Ruttan
 * @Date 10/17/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan _________ 10/17/2024 ______________
//
// ____ 301580889______
//

#include <exception>
#include <iostream>

int main() {
    std::array<int, 10> x;
    int index = 20; // Example index

    try {
     errno = 25;
        x.at(index) = 100; // at() throws an exception if index is out of bounds
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
     std::cerr << "Error: " << strerror(errno) << std::endl;
  return 0;
}