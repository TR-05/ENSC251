#pragma once

#include <math.h>

#include <vector>
namespace tntnlib
{
// uses 4 points and point spacing to generate a path
class Path
{
    // The Path class represents a path defined by a number of points.
   public:
    // Constructor for the Path class.
    // Initializes the number of points and creates vectors of that size for each attribute.
    Path(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, float pointSpacing, bool generate = true)
        : x0(x0),
          y0(y0),
          x1(x1),
          y1(y1),
          x2(x2),
          y2(y2),
          x3(x3),
          y3(y3),
          x(0),
          y(0),
          theta(0),
          t(1),
          curvature(0),
          lengthAtT(0),
          d1x(0),
          d1y(0),
          d2x(0),
          d2y(0),
          pointSpacing(pointSpacing),
          c1x(x3 - (3.0 * x2) + (3.0 * x1) - x0),
          c2x((3.0 * x2) - (6.0 * x1) + (3.0 * x0)),
          c3x((3.0 * x1) - (3.0 * x0)),
          c1y(y3 - (3.0 * y2) + (3.0 * y1) - y0),
          c2y((3.0 * y2) - (6.0 * y1) + (3.0 * y0)),
          c3y((3.0 * y1) - (3.0 * y0))
    {
        if (generate)
            generatePath();
    }

    Path()
        : x0(0),
          y0(0),
          x1(0),
          y1(0),
          x2(0),
          y2(0),
          x3(0),
          y3(0),
          x(0),
          y(0),
          theta(0),
          t(1),
          curvature(0),
          lengthAtT(0),
          d1x(0),
          d1y(0),
          d2x(0),
          d2y(0),
          pointSpacing(0),
          c1x(0),
          c2x(0),
          c3x(0),
          c1y(0),
          c2y(0),
          c3y(0)
    {
    }
    // Copy constructor for the Path class.
    Path(const Path& other)
        : x0(other.x0), y0(other.y0), x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), numberOfPoints(other.numberOfPoints), x(other.x), y(other.y), theta(other.theta), t(other.t), curvature(other.curvature), lengthAtT(other.lengthAtT), d1x(other.d1x), d1y(other.d1y), d2x(other.d2x), d2y(other.d2y), length(other.length), c1x(other.c1x), c2x(other.c2x), c3x(other.c3x), c1y(other.c1y), c2y(other.c2y), c3y(other.c3y), pointSpacing(other.pointSpacing)
    {
    }

    float x0, y0, x1, y1, x2, y2, x3, y3;
    int numberOfPoints = 0;
    std::vector<float> x, y, theta, t, curvature, lengthAtT, d1x, d1y, d2x, d2y;
    float length = 0;   // The total length of the path
    float genTime = 0;  // The time it took to generate the path
    void printPath();
    void savePath();
    
    // adds the points of another path to the end of this path
    Path operator+=(const Path& other);
    float pointSpacing;

   private:
    float xAt(float t);
    float yAt(float t);
    float d1xAt(float t);
    float d1yAt(float t);
    float d2xAt(float t);
    float d2yAt(float t);
    float thetaAt(float t);
    void generatePath();
    double c1x, c2x, c3x, c1y, c2y, c3y;
};
}  // namespace tntnlib
