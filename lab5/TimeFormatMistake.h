/**
 * @file TimeFormatMistake.h
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

#include <iostream>
#include <exception>

class TimeFormatMistake : public std::exception {
    private:
    const char * message;

    public:
    TimeFormatMistake(const char * msg) : message(msg) {}
    const char * what () {
        return message;
    }
};
