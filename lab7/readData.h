/**
 * @file readData.h
 * @author Trevor Ruttan
 * @Date 11/19/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____11/19/2024______________
//
// ____ 301580889 ______
//

#pragma once

// Read through all data in a given csv file, storing the date as a string and
// the price as a float while doing this create ordered lists of the following:
// Average Price per Year, Average Price per Month, Highest and Lowest Price per
// Year. also create ordered lists of prices sorted low to high and high to low
// (only need one and can just reverse the other)

#include <string>
#include <unordered_map>
#include <vector>

using namespace ::std;

/**
 * @brief Store the data and price data from the given csv file
 *
 * @param filename
 */
void read(string filename);

/**
 * @brief Calculates and prints the average stock price for each year in the
 * data
 *
 */
void averagePricePerYear();

/**
 * @brief Calculates and prints the average stock price for each month in the
 * data
 *
 */
void averagePricePerMonth();

/**
 * @brief finds and prints the highest and lowest stock prices for each year in
 * the data
 *
 */
void findHighestAndLowestPricesPerYear();

/**
 * @brief Generates a csv file with the stock prices sorted from lowest to
 * highest
 *
 */
void generateLowToHigh();

/**
 * @brief Generates a csv file with the stock prices sorted from highest to
 * lowest
 *
 */
void generateHighToLow();

/**
 * @brief Poll the user for an action to take
 *
 * @return true if the user wants to quit
 */
bool pollUser();