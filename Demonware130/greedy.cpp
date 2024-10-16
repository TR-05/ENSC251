// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <cstdio>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


//Strategy:
// Sum all elements in A and compare to the number of elements in A to determine if possible
// initial idea: forward / backward pass like in 2mp to cascade elements over
// may be slow, but will work
// sorts but not min ):

// Math based approach?
// find excess total bricks in A = min moves
// left and right most elements are special cases, always push inward
// maybe push inward from both sides simultaneously? Island case: 8, 14, 8

/*
int moves = 0;
void cascadeForward(std::vector<int> &A) {
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] > 10) {
            int excess = A[i] - 10;
            moves += excess;
            A[i+1] += excess;
            A[i] = 10;
        }
    }
}

void cascadeBackward(std::vector<int> &A) {
    for (int i = A.size(); i > 0; i--) {
        if (A[i] > 10) {
            int excess = A[i] - 10;
            moves += excess;
            A[i-1] += excess;
            A[i] = 10;
        }
    }
}
*/


bool checkElements(std::vector<int> &A) {
    int sum = 0;
    for (size_t i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    if (sum % 10 != 0) {
        return false;
    }
    return true;
}


int greedySolve(std::vector<int>& A) {
    int moves = 0;
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        while (A[i] != 10) {
            if (A[i] < 10) {
                A[i]++;
                A[i + 1]--;
            } else {
                A[i]--;
                A[i + 1]++;
            }
            moves++;
        }
    }
    return moves;
}
int solution(std::vector<int> &A) {
    // Implement your solution here
    if (!checkElements(A)) {
        printf("Not possible\n");
        return -1;
    }
    else {
        int minimumMoves = greedySolve(A);
        printf("Moves: %d\n", minimumMoves);
        for (int i = 0; i < A.size(); i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
        return minimumMoves;
    }
}


int main() {
    // Test vector 1
    std::vector<int> A = {7, 15, 10, 8};
    solution(A);

    // Test vector 2
    std::vector<int> A2 = {10, 10, 10, 10};
    solution(A2);

    // Test vector 3
    std::vector<int> A3 = {5, 15, 5, 15};
    solution(A3);

    // Test vector 4
    std::vector<int> A4 = {20, 0, 20, 0};
    solution(A4);

    // Test vector 5
    std::vector<int> A5 = {9, 11, 10, 10};
    solution(A5);

    // Test vector 6
    std::vector<int> A6 = {8, 12, 9, 11};
    solution(A6);

    // Test vector 7
    std::vector<int> A7 = {6, 14, 7, 13};
    solution(A7);

    // Test vector 8
    std::vector<int> A8 = {1, 19, 2, 18};
    solution(A8);

    // Test vector 9
    std::vector<int> A9 = {3, 17, 4, 16};
    solution(A9);

    // Test vector 10
    std::vector<int> A10 = {0, 20, 5, 15};
    solution(A10);


    return solution(A);
}
/*
g++ Task2.cpp -o Task2
./Task2
*/