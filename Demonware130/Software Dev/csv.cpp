#include <stdio.h>
#include <vector>
#include <string>
// Plan -> find column index of C in S by comparing strings.
// -> find the value in the column found and add it to a vector of ints, then skip past /n and repeat

std::vector<int> findNewlineIndices(const std::string &S) {
    std::vector<int> newlineIndices;
    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == '\n') {
            newlineIndices.push_back(i);
        }
    }
    return newlineIndices;
}

int findBiggest(std::string &S, std::string &C) {
    // Implement your solution here
    size_t position1 = S.find(C+",");
    size_t position2 = S.find(C+"\n");
    size_t position = position1 < position2 ? position1 : position2;
    //printf("Position: %d\n", int(position));
    int commaCount = 0;
    for (size_t i = 0; i < position+1; i++) {
        if (S[i] == ',') {
            //printf("c: %d\n",int(commaCount));
            commaCount++;
        }
    }
    //printf("Comma count: %d\n", commaCount);
    std::vector<int> newlineIndices = findNewlineIndices(S);
    // for each line skip past the version commaCount commas then take the value into a vector of ints
    std::vector<int> values;
    for (size_t i = 0; i < newlineIndices.size(); i++) {
        int commasFound = 0;
        int searchPos = newlineIndices[i] + 1;
        int j = 0;
        while(commasFound < commaCount) {
            //printf("j: %d\n", j);
            if (S[searchPos+j] == ',') {
                commasFound++;
            }
            j++;
        }
        //printf("SearchPos: %d\n", searchPos);
        std::string num = "";
        int k = 0;
        searchPos += j;
        while ( (S[searchPos+k] != ',' && S[searchPos+k] != '\n') && searchPos+k < S.length()) {
            num += S[searchPos+k];
            //printf("num: %s\n", num.c_str());
            k++;
        }
        //printf("num: %s\n", num.c_str());
        values.push_back(stoi(num));
    }
    int biggest = values[0];
    for (size_t i = 0; i < values.size(); i++) {
        //printf("values[%d]: %d\n", int(i), values[i]);
        if (values[i] > biggest) {
            biggest = values[i];
        }
    }
    return biggest;
}


int main()
{
    std::string S = "city,temp2,temp\nParis,7,-3\nDubai,4,-4\nPorto,-1,-2";
    std::string C = "temp";
    int returnValue = findBiggest(S, C);
    //printf("%d\n", returnValue);
    return returnValue;
}


/*
g++ csv.cpp -o csv
./csv
*/