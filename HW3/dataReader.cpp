/**
 * @file dataReader.cpp
 * @author Trevor Ruttan
 * @Date 11/29/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____11/27/2024______________
//
// ____ 301580889 ______
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "movieRatings.h"

using namespace std;

/**
 * @brief Collects data from a file and stores it in a map
 * @param file ifstream
 * @return unordered_map<string, vector<int>>
 */
unordered_map<string, vector<int>> collectData(ifstream &file) {

  string line;
  unordered_map<string, vector<int>> dataMap;
  while (getline(file, line)) {
    int startPos = line.find(',') + 2;
    string key = line.substr(startPos, line.length() - startPos);
    int value = stoi(line.substr(0, startPos - 2));
    dataMap[key].push_back(value);
  }
  file.close();
  return dataMap;
}

/**
 * @brief Sorts movies by rating
 * @param dataMap unordered_map<string, vector<int>>
 * @return vector<Movie>
 */
vector<MovieRating> sortMovies(unordered_map<string, vector<int>> &dataMap) {
  vector<MovieRating> ratings;
  for (auto movie : dataMap) {
    int sum = 0;
    int count = 0;
    for (int score : movie.second) {
      sum += score;
      count++;
    }
    float rating = static_cast<float>(sum) / movie.second.size();
    MovieRating m(movie.first, rating, count);
    ratings.push_back(m);
  }
  sort(ratings.begin(), ratings.end(), compareMoviesRating);
  return ratings;
}

/**
 * @brief Prints movies to the console
 * @param movies vector<Movie>
 */
void printMovies(vector<MovieRating> &movies) {
  cout << "\nSorted by rating:\n";
  for (int i = 0; i < movies.size(); i++) {
    movies[i].printRating();
  }
  cout << "\n";
}

/**
 * @brief Reads data from a file and processes it
 * @param filename string
 */
void readData(string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Failed to open the file." << endl;
    return;
  }

  unordered_map<string, vector<int>> dataMap = collectData(file);
  vector<MovieRating> movies = sortMovies(dataMap);
  printMovies(movies);
}