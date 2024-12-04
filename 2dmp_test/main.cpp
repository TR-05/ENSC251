#include "cubicBezier.h"
#include "mp3.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace tntnlib;

int main() {
  Path path(0,0, 0,20, 20,0, 20,20, 0.25);
  //path.printPath();
  path.savePath();

  auto start = std::chrono::high_resolution_clock::now();
  mp3 mp(path, 0, 0, 0, 80, 1.8, 120, 120, 10.5, false);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(end - start);
  std::cout << "Time taken to execute mp3 constructor: " << duration.count() << " ms" << std::endl;

  std::ofstream v("profile_output.txt");

  for (size_t i = 0; i < mp.wd.size(); i++) {
    v << mp.wd[i].s << "," << mp.wd[i].v;
    v << "," << mp.wd[i].vl;
    v << "," << mp.wd[i].vr << "\n";

    std::cout << mp.wd[i].s << "," << mp.wd[i].vl << ", " << mp.wd[i].vr << "\n";


  }
  v.close();

  /*for (size_t i = 0; i < mp.wd.size(); i++) {
    printf("P: (%.2f, %.2f, %.2f), Curvature: %.2f, s: %.2f, ds: %.2f, vl: %.2f, vr: %.2f, v: %.2f, w: %.2f, t: %.2f\n",
           mp.wd[i].pose.x, mp.wd[i].pose.y, mp.wd[i].pose.theta, mp.wd[i].curvature, mp.wd[i].s, mp.wd[i].ds, mp.wd[i].vl, mp.wd[i].vr, mp.wd[i].v, mp.wd[i].w, mp.wd[i].t);
    
    }*/
  return 0;
}