#include "include/cubicBezier.h"
#include "include/motionProfile2d.h"
#include "include/motionProfile1d.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace tntnlib;

int main() {
  /*
  Path path(0,0, 0,20, 20,0, 20,20, 0.25);
  //path.printPath();
  path.savePath();

  auto start = std::chrono::high_resolution_clock::now();
  MotionProfile2d mp(path, 0, 0, 0, 80, 1.5, 120, 120, 10.5, false, false);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(end - start);
  std::cout << "Time taken to execute mp3 constructor: " << duration.count() << " ms" << std::endl;

  std::ofstream out("profile_output.txt");

  for (size_t i = 0; i < mp.wd.size(); i++) {
    v << mp.wd[i].s << "," << mp.wd[i].v;
    v << "," << mp.wd[i].vl;
    v << "," << mp.wd[i].vr << "\n";

    //std::cout << mp.wd[i].s << "," << mp.wd[i].vl << ", " << mp.wd[i].vr << "\n";
  }
  v.close();
  */
  std::ofstream out("data.txt");
  MotionProfile1d mp(6, 62, 60, 60);
  for (size_t i = 0; i < mp.v.size(); i++) {
    out << mp.t[i] << "," << mp.v[i] << "\n";
  }

  MotionProfile1d mp2(-7, 62, 60, 60);
  for (size_t i = 0; i < mp2.v.size(); i++) {
    out << mp2.t[i] << "," << mp2.v[i] << "\n";
  }


  return 0;
}