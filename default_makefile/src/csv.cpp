#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

void populate()
{
    std::ofstream data_file("../../data.csv");
    data_file.clear();
    data_file << "t,F\n";
    float omega = 1;
    for (int t = 0; t <= 20; t++) {
        float u = sin(omega * t);
        float du = cos(omega * t); 
        float F = (0.5 * u * fabs(u)) + du; 

        std::cout << "t = " << t << "\t\tF = " << F << std::endl;
        data_file << t << "," << F << ",\n";
    }

    data_file.close();
}

void read()
{
    std::ifstream data_file("../../data.csv");
    std::string line;
    std::vector<float> t;
    std::vector<float> F;

    // Skip the header line
    std::getline(data_file, line);

    while (std::getline(data_file, line)) {
        std::stringstream line_stream(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(line_stream, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() == 2) {
            try {
                t.push_back(std::stof(row[0]));
                F.push_back(std::stof(row[1]));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid data: " << line << std::endl;
            }
        }
    }

    printf("\n\n\nt,F\n");
    for (size_t i = 0; i < t.size(); i++) {
        std::cout << t[i] << "," << F[i] << std::endl;
    }

    data_file.close();
}


