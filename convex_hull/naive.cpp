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
  int n = points.size();
  vector<bool> included(n, false);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (i == j)
        continue;

      bool neg = false;
      bool pos = false;

      for (int k = 0; k < n; k++) {
        if (k == i || k == j)
          continue;

        int res = orientation(points[i], points[j], points[k]);
        neg |= (res < 0);
        pos |= (res > 0);
      }

      if (!(neg && pos)) {
        included[i] = true;
        included[j] = true;
      }
    }
  }

  vector<Point2D> ans;
  for (int i = 0; i < n; i++) {
    if (included[i])
      ans.push_back(points[i]);
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