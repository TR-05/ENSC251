#include "cubicBezier.h"
#include "mp3.h"
#include <iostream>
#include <fstream>

using namespace tntnlib;

int main() {
  Path path(0,0, 0,20, 20,0, 20,20, 0.25);
  path.printPath();
  path.savePath();

  mp3 mp(path, 0, 0, 0, 30, 1.3, 120, 120, 10.5, 0);

  std::ofstream outFile2("profile_output.txt");
  for (size_t i = 0; i < mp.wd.size(); i++) {
    outFile2 << mp.wd[i].s << "," << mp.wd[i].v << "\n";
    std::cout << mp.wd[i].s << "," << mp.wd[i].v << "\n";
  }
  outFile2.close();

  /*for (size_t i = 0; i < mp.wd.size(); i++) {
    printf("P: (%.2f, %.2f, %.2f), Curvature: %.2f, s: %.2f, ds: %.2f, vl: %.2f, vr: %.2f, v: %.2f, w: %.2f, t: %.2f\n",
           mp.wd[i].pose.x, mp.wd[i].pose.y, mp.wd[i].pose.theta, mp.wd[i].curvature, mp.wd[i].s, mp.wd[i].ds, mp.wd[i].vl, mp.wd[i].vr, mp.wd[i].v, mp.wd[i].w, mp.wd[i].t);
    
    }*/
  return 0;
}