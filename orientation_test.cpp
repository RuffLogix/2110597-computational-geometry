#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Point2D {
  double x, y;

  Point2D operator-(Point2D rhs) {
    return Point2D{this->x - rhs.x, this->y - rhs.y};
  }
};

/*
  value > 0: CCW
  value < 0: CW
  value = 0: Collinear
*/
bool orientation(Point2D p1, Point2D p2, Point2D p3) {
  Point2D p21 = p2 - p1;
  Point2D p31 = p3 - p1;

  double value = p21.x * p31.y - p21.y * p31.x;
  return value > EPS ? 1 : value < -EPS ? -1 : 0;
}

int main() { return 0; }