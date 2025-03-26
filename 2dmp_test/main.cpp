#include "include/xdrive.h"
#include <iostream>

int main() {
  std::array<float, 4> velocities = wheelVelocities(45, 50, .5, 50, 8, 90);
  std::cout << "vfl: " << velocities[0] << " vbl: " << velocities[1]
            << " vfr: " << velocities[2] << " vbr: " << velocities[3]
            << std::endl;

  return 0;
}
