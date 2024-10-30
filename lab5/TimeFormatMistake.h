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

using namespace std;

/**
 * @brief TimeFormatMistake is a custom exception class that is thrown when the user enters an invalid time.
 * 
 */
class TimeFormatMistake : public std::exception {
    private:
    string message;
    string standardMessage = "There is no such time as ";
    string outputMessage = "";  
    public:
    TimeFormatMistake(const std::string& msg) : message(msg) {}
    const char * what () {
        outputMessage = standardMessage + message + "\n";
        return (outputMessage.c_str());
    }
};
