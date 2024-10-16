#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Plan: 
loop from left to right through A, summing each pair, and skipping if the last sum = sum. use an unordered_map to store the sum and the count as unordered_map is significantly faster than using a vector of pairs because the unordered_map does not require a linear search each for each sum. Hash Maps!
*/

int solution(vector<int> &A) {
  unordered_map<int, int> count;
  int lastSum = -1;
  int maxCount = 0;
  int maxSum = 0;

  for (size_t i = 0; i < A.size() - 1; i ++) {
    int sum = A[i] + A[i + 1];
    if (sum != lastSum) {
      count[sum]++;
      if (count[sum] > maxCount) {
        maxCount = count[sum];
        maxSum = sum;
      }
      lastSum = sum;
    } else {
      lastSum = -1;
    }
  }

  //cout << "max: " << maxCount << endl;
  //cout << "sum: " << maxSum << endl;
  return maxCount;
}


int main() {
  vector<int> A = {10, 1, 3, 1, 2, 2, 1, 0, 4}; // 3
   //A = {5, 3, 1, 3, 2, 3}; // 1
   //A = {9, 9, 9, 9, 9}; // 2
  int result = solution(A);
  cout << result << endl;
  return 0;
}
/*
g++ task2.cpp -o task2
./task2
*/

/*
//v1 vector of pairs
// Plan: cascade left to right summing the elements, and use a vector to store
// the count, skipping if the last element added = this one
int solution2(vector<int> &A) {
  vector<pair<int, int>> count;
  int lastSum = 0;
  for (size_t i = 0; i < A.size() - 1; i++) {
    int sum = A[i] + A[i + 1];
    // cout << "sum: " << sum << endl;
    bool found = false;
    for (size_t j = 0; j < count.size(); j++) {
      //cout << count[j].first << " == " << sum << "i: " << i << " j: " << j << endl; if (count[j].first == sum) { if (lastSum != sum) { count[j].second++;
          found = true;
          lastSum = sum;
          //cout << " incremented: " << sum << endl;
          break;
        } else {
          //cout << " skipping: " << sum << endl;
          found = true;
          lastSum = -1;
          break;
        }
      }
    }
    if (!found) {
      count.push_back(make_pair(sum, 1));
        lastSum = sum;
      // cout << "pushed: " << sum << endl;
    }
  }
  int max = 0;
  int maxIndex = 0;
  for (size_t i = 0; i < count.size(); i++) {
    if (count[i].second > max) {
        max = count[i].second;
      maxIndex = i;
    }
  }
  cout << "max: " << count[maxIndex].second << endl;
  cout << "sum: " << count[maxIndex].first << endl;
  return count[maxIndex].second;
}

*/