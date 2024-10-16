#include <cstdio>
#include <vector>

using namespace std;
/*
Note: Yesterday I did the codility test for Demonware's Software Development
Internship, and it also used this exact question, so I will be basing this attempt off of the approach I used for that one, but improving the code for correctness and robustness.

Plan:
-> First sum all elements in A and compare to the number of elements in A to determine if possible.
-> next use a greedy approach where the current element will either give or steal from the next in order to reach 10 bricks from left to right.

New fail case found, 2, 1, 1, 36, makes negative bricks? not sure if thats allowed.
-> add a check to the greedy loop to stop stealing if the next box is at 1
-> add a second greedy loop from right to left to clear up any failure cases caused by the >0 check.
*/


bool checkElements(vector<int> &A) {
  int sum = 0;
  for (size_t i = 0; i < A.size(); i++) {
    sum += A[i];
  }
  if (sum % 10 != 0) {
    return false;
  }
  return true;
}

int greedySolve(vector<int> &A) {
  int moves = 0;
  int n = A.size();

  // Greedy Pass from left to right
  for (int i = 0; i < n - 1; i++) {
    while (A[i] != 10) {
      if (A[i] < 10) {
        if (A[i + 1] > 0) {
          A[i]++;
          A[i + 1]--;
        } else {
          break;
        }
      } else {
        A[i]--;
        A[i + 1]++;
      }
      moves++;
    }
  }

  // Greedy Pass from right to left (to handle extra failure cases like 2, 1, 1, 36)
  for (int i = 0; i < n - 1; i++) {
    int j = n - 1 - i;
    while (A[j] != 10) {
      if (A[j] < 10) {
        if (A[j - 1] > 0) {
          A[j]++;
          A[j - 1]--;
        } else {
          break;
        }
      } else {
        A[j]--;
        A[j - 1]++;
      }
      moves++;
    }
  }
  return moves;
}
int solution(vector<int> &A) {
  /*
  // Print out the given vector
  for (size_t i = 0; i < A.size(); i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  */
  if (!checkElements(A)) {
    //printf("Not possible\n");
    return -1;
  } else {
    int minimumMoves = greedySolve(A);
    /*
    //
    printf("Moves: %d\n", minimumMoves);
    for (size_t i = 0; i < A.size(); i++) {
      printf("%d ", A[i]);
    }
    printf("\n\n");
    */
    return minimumMoves;
  }
}
int main() {
  // Test vector 1
  vector<int> A = {7, 15, 10, 8};
  solution(A);

  // Test vector 2
  vector<int> A2 = {10, 10, 10, 10};
  solution(A2);

  // Test vector 3
  vector<int> A3 = {5, 15, 5, 15};
  solution(A3);

  // Test vector 4
  vector<int> A4 = {20, 0, 20, 0};
  solution(A4);

  // Test vector 5
  vector<int> A5 = {9, 11, 10, 10};
  solution(A5);

  // Test vector 6
  vector<int> A6 = {8, 12, 9, 11};
  solution(A6);

  // Test vector 7
  vector<int> A7 = {6, 14, 7, 13};
  solution(A7);

  // Test vector 8
  vector<int> A8 = {1, 19, 2, 18};
  solution(A8);

  // Test vector 9
  vector<int> A9 = {3, 17, 4, 16};
  solution(A9);

  // Test vector 10
  vector<int> A10 = {0, 20, 5, 15};
  solution(A10);

  vector<int> A11 = {2, 1, 1, 36};
  solution(A11);

  return solution(A);
}
/*
g++ Task2.cpp -o Task2
./Task2
*/