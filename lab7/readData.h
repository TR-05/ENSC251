/**
 * @file readData.h
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

#pragma once

// Read through all data in a given csv file, storing the date as a string and the price as a float
// while doing this create ordered lists of the following: Average Price per Year, Average Price per Month, Highest and Lowest Price per Year.
// also create ordered lists of prices sorted low to high and high to low (only need one and can just reverse the other)

#include <string>
#include <unordered_map>

using namespace::std;

void read(string filename);

// Read the data from the csv and store it in a hash map, store the dates in a vector as the keys.
// then can use a std::array to order the prices by year and month
extern vector<string> dates;
extern unordered_map<string, float> unorderedPrices;

