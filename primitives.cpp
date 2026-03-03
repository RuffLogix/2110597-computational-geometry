#include <bits/stdc++.h>

using namespace std;

struct Point2D {
  double x, y;

  Point2D operator*(double t) { return Point2D{this->x * t, this->y * t}; }
  Point2D operator+(Point2D rhs) {
    return Point2D{this->x + rhs.x, this->y + rhs.y};
  }
};

struct Point3D {
  double x, y, z;

  Point3D operator*(double t) {
    return Point3D{this->x * t, this->y * t, this->z * t};
  }
  Point3D operator+(Point3D rhs) {
    return Point3D{this->x + rhs.x, this->y + rhs.y, this->y + rhs.z};
  }
};

struct Vector : Point2D {};

struct Segment {
  Point2D p1, p2;
};

// Pros: Easy to visualize and generate points
struct ParametricLine {
  Point2D p, v;

  Point2D get_position(double t) { return this->p + this->v * t; }
};

// Pros: Powerful for "side-of-line" tests
struct ImplicitLine {
  double a, b, c;

  // ax + by + c = 0
  void initial_parameters(Point2D p1, Point2D p2) {
    this->a = p1.y - p2.y;
    this->b = p2.x - p1.x;
    this->c = -this->a * p1.x - this->b * p1.y;
  }
};

int main() { return 0; }