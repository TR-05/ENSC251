/**
 * @file movieRatings.cpp
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
// _____ Trevor Ruttan ____ _____11/29/2024______________
//
// ____ 301580889 ______
//

/**
 * @brief Struct to hold finalized movie data
 */

#include "movieRatings.h"
#include <iostream>

using namespace std;

/**
 * @brief prints out the movie title, rating, and number of reviews
 */
void MovieRating::printRating() {
  if (ratingCount == 1) {
    cout << title << ": " << ratingCount << " review, average of " << rating
         << " / 5" << endl;
  } else {
    cout << title << ": " << ratingCount << " reviews, average of " << rating
         << " / 5" << endl;
  }
}

/**
 * @brief Compare movies by rating for the purpose of sorting
 * @param a Movie a
 * @param b Movie b
 * @return bool
 */
bool compareMoviesRating(const MovieRating &a, const MovieRating &b) {
  return a.rating > b.rating;
}