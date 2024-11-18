/**
 * @file readData.cpp
 * @author Trevor Ruttan
 * @Date 11/18/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____11/18/2024______________
//
// ____ 301580889 ______
//

#include "readData.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace ::std;

vector<string> dates;
unordered_map<string, float> unorderedPrices;
unordered_map<int, float> days;
unordered_map<int, float> monthTotal;
unordered_map<int, float> yearTotal;
int numberOfYears = 0;
void read(string filename) {
  fstream file(filename);

  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string line;
  getline(file, line); // Skip the first line
  while (getline(file, line)) {
    size_t firstComma = line.find_first_of(',');
    string date = line.substr(0, firstComma);
    size_t secondComma = line.find_first_of(',', firstComma + 1);
    size_t thirdComma = line.find_first_of(',', secondComma + 1);
    size_t firstSlash = line.find_first_of('/');
    size_t secondSlash = line.find_first_of('/', firstSlash + 1);
    int day = stoi(line.substr(0, firstSlash));
    int month = stoi(line.substr(firstSlash + 1, secondSlash - firstSlash - 1));
    int year = stoi(line.substr(secondSlash + 1, firstComma - secondSlash));
    
    cout << "Day: " << day << endl;
    cout << "Month: " << month << endl;
    cout << "Year: " << year << endl;
    float price =
        stof(line.substr(secondComma + 1, thirdComma - secondComma - 1));
    dates.push_back(date);
    unorderedPrices[date] = price;
  }
}