/**
 * @file pairs.h
 * @author Trevor Ruttan
 * @Date 10/22/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____10/22/2024______________
//
// ____ 301580889 ______
//

#include <iostream>
using namespace std;

class Pairs {
public:
  /**
   * @brief Default constructor for Pairs
   */
  Pairs();

  /**
   * @brief Constructor for Pairs, taking in one integer input, setting the
   * second number to 0
   * @param first The first number in the pair
   */
  Pairs(int first);

  /**
   * @brief Constructor for Pairs, taking in two integer inputs
   * @param first The first number in the pair
   * @param second The second number in the pair
   */
  Pairs(int first, int second);

  // other members and friends

  /**
   * @brief Overloaded input operator for Pairs, reads input in the form '(int,
   * int)', if formatted incorrectly, does not modify object
   * @param ins The input stream
   * @param pair The Pairs object to modify
   */
  friend istream &operator>>(istream &ins, Pairs &pair);

  /**
   * @brief Overloaded output operator for Pairs, outputs Pair in the form
   * '(int, int)'
   * @param outs The output stream
   * @param pair The Pairs object to modify
   */
  friend ostream &operator<<(ostream &outs, const Pairs &pair);

  /**
   * @brief Overloaded addition operator for Pairs, adds two Pairs together in
   * the form (a, b) + (c, d) = (a + c, b + d)
   */
  friend Pairs operator+(const Pairs &first, const Pairs &second);

  /**
   * @brief Overloaded subtraction operator for Pairs, subtracts two Pairs
   * together in the form (a, b) - (c, d) = (a - c, b - d)
   */
  friend Pairs operator-(const Pairs &first, const Pairs &second);

  /**
   * @brief Overloaded multiplication operator for Pairs, multiplies two Pairs
   * together in the form (a, b) * (c, d) = (a * c, b * d)
   */
  friend Pairs operator*(const Pairs &first, const Pairs &second);

private:
  int firstNumber;
  int secondNumber;
};