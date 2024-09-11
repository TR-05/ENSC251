#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

void populate()
{
    std::ofstream Morison_File("linear_wave_loading.csv"); // Opening file to print info to
    Morison_File << "Time Force(N/m)" << std::endl; // Headings for file
    float omega = 1;
    for (int t = 0; t <= 20; t++) {
        float u = sin(omega * t);
        float du = cos(omega * t); 
        float F = (0.5 * u * fabs(u)) + du; 

        std::cout << "t = " << t << "\t\tF = " << F << std::endl;
        Morison_File << t << " " << F << std::endl; // Printing to file
    }

    Morison_File.close();
}
