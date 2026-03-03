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
  int current_index = -1;
  for (int i = 0; i < points.size(); i++) {
    if (current_index == -1 || points[i].y < points[current_index].y) {
      current_index = i;
    }
  }
  int start = current_index;

  vector<Point2D> ans;
  do {
    ans.push_back(points[current_index]);

    int target_index = (current_index + 1) % points.size();
    for (int i = 0; i < points.size(); i++) {
      if (i == current_index)
        continue;

      if (orientation(points[current_index], points[target_index], points[i]) >
          0) {
        target_index = i;
      }
    }
    current_index = target_index;
  } while (start != current_index);
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