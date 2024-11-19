/**
 * @file readData.cpp
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

#include "readData.h"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> dates;
unordered_map<string, float> unorderedPrices;

/**
 * @brief Store the data and price data from the given csv file
 *
 * @param filename
 */
void read(string filename) {
  fstream file(filename);

  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string line;
  getline(file, line); // Skip Header
  while (getline(file, line)) {
    stringstream ss(line);
    string date, priceStr;
    getline(ss, date, ',');     // Read date (column 1)
    getline(ss, priceStr, ','); // Skip column 2
    getline(ss, priceStr, ','); // Read price (column 3)

    try {
      float price = stof(priceStr);
      unorderedPrices[date] = price;
      dates.push_back(date);
    } catch (const invalid_argument &e) {
      cerr << "Invalid price value: " << priceStr << " on line: " << line
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Price value out of range: " << priceStr << " on line: " << line
           << endl;
    }
  }

  file.close();
}

/**
 * @brief Calculates and prints the average stock price for each year in the
 * data
 *
 */
void averagePricePerYear() {
  unordered_map<int, pair<float, int>> yearData; // year -> (total price, count)
  vector<int> years;
  for (const string &date : dates) {
    int month, day, year;
    sscanf(date.c_str(), "%d/%d/%d", &month, &day, &year);
    if (find(years.begin(), years.end(), year) == years.end()) {
      years.push_back(year);
    }
    yearData[year].first +=
        unorderedPrices[date];  // sum of prices for a given year
    yearData[year].second += 1; // count of prices for a given year
  }

  for (const int &year : years) {
    float total = yearData[year].first;
    int count = yearData[year].second;
    float average = total / count;
    cout << year << " Average Price: " << average << endl;
  }
}

/**
 * @brief Calculates and prints the average stock price for each month in the
 * data
 *
 */
void averagePricePerMonth() {
  unordered_map<int, unordered_map<int, pair<float, int>>>
      monthData; // year -> month -> (total price, count)

  for (const string &date : dates) {
    int year, month, day;
    sscanf(date.c_str(), "%d/%d/%d", &month, &day, &year);
    monthData[year][month].first += unorderedPrices[date];
    monthData[year][month].second += 1;
  }

  for (const auto &yearEntry : monthData) {
    int year = yearEntry.first;
    cout << "Year: " << year << endl;
    for (int month = 1; month <= 12; ++month) {
      if (yearEntry.second.find(month) != yearEntry.second.end()) {
        float total = yearEntry.second.at(month).first;
        int count = yearEntry.second.at(month).second;
        float average = total / count;
        cout << "  Month: " << month << ", Average Price: " << average << endl;
      }
    }
  }
}

/**
 * @brief finds and prints the highest and lowest stock prices for each year in
 * the data
 *
 */
void findHighestAndLowestPricesPerYear() {
  unordered_map<int, pair<string, float>>
      highestPrices;                                    // year -> (date, price)
  unordered_map<int, pair<string, float>> lowestPrices; // year -> (date, price)

  for (const string &date : dates) {
    int year, month, day;
    sscanf(date.c_str(), "%d/%d/%d", &month, &day, &year);
    float price = unorderedPrices[date];

    if (highestPrices.find(year) == highestPrices.end() ||
        price > highestPrices[year].second) {
      highestPrices[year] = {date, price};
    }

    if (lowestPrices.find(year) == lowestPrices.end() ||
        price < lowestPrices[year].second) {
      lowestPrices[year] = {date, price};
    }
  }

  for (const auto &entry : highestPrices) {
    int year = entry.first;
    cout << year << " Highest Price: " << entry.second.second << " on "
         << entry.second.first << endl;
  }

  for (const auto &entry : lowestPrices) {
    int year = entry.first;
    cout << year << " Lowest Price: " << entry.second.second << " on "
         << entry.second.first << endl;
  }
}

/**
 * @brief Generates a csv file with the stock prices sorted from lowest to
 * highest
 *
 */
void generateLowToHigh() {
  cout << "Generating low to high list" << endl;
  vector<pair<string, float>> priceList;

  for (const auto &date : dates) {
    priceList.push_back({date, unorderedPrices[date]});
  }

  // Sort from lowest to highest
  sort(priceList.begin(), priceList.end(),
       [](const pair<string, float> &a, const pair<string, float> &b) {
         return a.second < b.second;
       });

  ofstream low2HighFile("low2High.csv");
  for (const auto &entry : priceList) {
    low2HighFile << entry.first << "," << entry.second << endl;
  }
  low2HighFile.close();
}

/**
 * @brief Generates a csv file with the stock prices sorted from highest to
 * lowest
 *
 */
void generateHighToLow() {
  cout << "Generating high to low list" << endl;
  vector<pair<string, float>> priceList;

  for (const auto &date : dates) {
    priceList.push_back({date, unorderedPrices[date]});
  }

  // Sort from highest to lowest
  sort(priceList.begin(), priceList.end(),
       [](const pair<string, float> &a, const pair<string, float> &b) {
         return a.second > b.second;
       });

  ofstream high2LowFile("high2Low.csv");
  for (const auto &entry : priceList) {
    high2LowFile << entry.first << "," << entry.second << endl;
  }
  high2LowFile.close();
}

/**
 * @brief Poll the user for an action to take
 *
 * @return true if the user wants to quit
 */
bool pollUser() {
  cout << "\nSelect From The Following Options: \n";
  cout << "a: Average Price Per Year: \n";
  cout << "b: Average Price Per Month: \n";
  cout << "c: Highest and Lowest Prices Per Year: \n";
  cout << "d: Generate Low To High List: \n";
  cout << "e: Generate High To Low List: \n";
  cout << "Any other character to exit \n";
  char response;
  cin >> response;
  bool quit = false;
  switch (response) {
  case ('a'):
    averagePricePerYear();
    break;
  case ('b'):
    averagePricePerMonth();
    break;
  case ('c'):
    findHighestAndLowestPricesPerYear();
    break;
  case ('d'):
    generateLowToHigh();
    break;
  case ('e'):
    generateHighToLow();
    break;
  default:
    quit = true;
    break;
  }
  return quit;
}