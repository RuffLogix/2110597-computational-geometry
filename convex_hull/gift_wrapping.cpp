#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Point2D {
  double x, y;

  Point2D operator-(const Point2D &rhs) const {
    return Point2D{
        this->x - rhs.x,
        this->y - rhs.y,
    };
  }
};

vector<Point2D> points;

int orientation(Point2D p1, Point2D p2, Point2D p3) {
  Point2D p21 = p2 - p1;
  Point2D p31 = p3 - p1;

  double value = p21.x * p31.y - p21.y * p31.x;
  return value > EPS ? 1 : value < -EPS ? -1 : 0;
}

vector<Point2D> convex_hull() {
  vector<bool> included(points.size());

  int current_index = -1;
  for (int i = 0; i < points.size(); i++) {
    if (i == -1 || points[i].y < points[current_index].y) {
      current_index = i;
    }
  }

  vector<Point2D> ans;
  while (!included[current_index]) {
    ans.push_back(points[current_index]);
    included[current_index] = true;

    int target_index = -1;
    double target_angle = 360.0;
    for (int i = 0; i < points.size(); i++) {
      if (i == current_index)
        continue;
      double angle = atan2(points[i].y - points[current_index].y,
                           points[i].x - points[current_index].x);

      if (target_index == -1 || angle < target_angle) {
        target_angle = angle;
        target_index = i;
      }
    }
    current_index = target_index;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    points.push_back(Point2D{x, y});
  }

  vector<Point2D> ans = convex_hull();

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].x << ' ' << ans[i].y << '\n';
  }

  return 0;
}