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

  bool operator==(const Point2D &rhs) const {
    return fabs(this->x - rhs.x) < EPS && fabs(this->y - rhs.y) < EPS;
  }

  bool operator!=(const Point2D &rhs) const {
    return !(fabs(this->x - rhs.x) < EPS && fabs(this->y - rhs.y) < EPS);
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

  sort(points.begin(), points.end(), [&](Point2D a, Point2D b) {
    if (fabs(a.x - b.x) < EPS)
      return a.y < b.y;
    return a.x < b.x;
  });

  vector<Point2D> upper_hull;
  for (int i = 0; i < n; i++) {
    while (upper_hull.size() >= 2 &&
           orientation(upper_hull[upper_hull.size() - 2], upper_hull.back(),
                       points[i]) <= 0) {
      upper_hull.pop_back();
    }
    upper_hull.push_back(points[i]);
  }

  vector<Point2D> lower_hull;
  for (int i = n - 1; i >= 0; i--) {
    while (lower_hull.size() >= 2 &&
           orientation(lower_hull[lower_hull.size() - 2], lower_hull.back(),
                       points[i]) <= 0) {
      lower_hull.pop_back();
    }
    lower_hull.push_back(points[i]);
  }

  upper_hull.pop_back();
  lower_hull.pop_back();

  vector<Point2D> ans = upper_hull;
  ans.insert(ans.end(), lower_hull.begin(), lower_hull.end());
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