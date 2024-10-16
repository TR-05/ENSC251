#include <algorithm>
#include <vector>
#include <cstdio>

//breakdown:
// L = maximum times a number can repeat
// K = maximum value of any number
// if broken, return false

// 1. find elements in v
// 2. loop through v skipping the last L elements
// -> if (v[i - L] == v[i] - L) return false
// end loop and if last element is K, return true

bool solution(std::vector<int> &values, int K, int L) {
    int n = values.size();
    std::vector<int> count(n + 1, 0); // line1
    for (int i = 0; i < n; i++) { // line2
        if (values[i] > K or ++count[values[i]] > L) { //line3
            return false;
        }
    }
    return values[n - 1] == K;
}

int main()
{
    std::vector<int> values = {4,2,5};
    int K = 5;
    int L = 2;
    bool result = solution(values, K, L);
    printf("Result: %d\n", result);

    return 0;
}


/*
g++ Task4.cpp -o Task4
./Task4
*/