#include "cubicBezier.h"
#include "mp3.h"
#include <iostream>
#include <fstream>

using namespace tntnlib;

int main() {
  Path path(0,0, 0,20, 20,0, 20,20, 0.25);
  path.printPath();
  path.savePath();

  mp3 mp(path, 0, 0, 0, 62, .5, 120, 120, 10.5, 0);

  std::ofstream outFile2("profile_output.txt");
  for (size_t i = 0; i < mp.wt.size(); i++) {
    outFile2 << mp.wt[i].t << "," << mp.wt[i].v << "\n";
    std::cout << mp.wt[i].t << "," << mp.wt[i].v << "\n";
  }
  outFile2.close();

  /*for (size_t i = 0; i < mp.wt.size(); i++) {
    printf("P: (%.2f, %.2f, %.2f), Curvature: %.2f, s: %.2f, ds: %.2f, vl: %.2f, vr: %.2f, v: %.2f, w: %.2f, t: %.2f\n",
           mp.wt[i].pose.x, mp.wt[i].pose.y, mp.wt[i].pose.theta, mp.wt[i].curvature, mp.wt[i].s, mp.wt[i].ds, mp.wt[i].vl, mp.wt[i].vr, mp.wt[i].v, mp.wt[i].w, mp.wt[i].t);
    
    }*/
  return 0;
}