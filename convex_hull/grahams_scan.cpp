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

long long dist(Point2D pivot, Point2D point) {
  Point2D diff = point - pivot;
  return diff.x * diff.x + diff.y * diff.y;
}

vector<Point2D> convex_hull() {
  int n = points.size();
  Point2D pivot = Point2D{-1e9, -1e9};
  for (int i = 0; i < n; i++) {
    if (i == 0 || pivot.y > points[i].y ||
        (pivot.y == points[i].y && pivot.x > points[i].x)) {
      pivot = points[i];
    }
  }

  sort(points.begin(), points.end(), [&](const Point2D &a, const Point2D &b) {
    if (a == pivot)
      return b != pivot;
    if (b == pivot)
      return false;

    int orient = orientation(pivot, a, b);

    if (orient == 0) {
      return dist(pivot, a) < dist(pivot, b);
    }

    return orient == 1;
  });

  vector<Point2D> ans;
  ans.push_back(points[0]);
  for (int i = 1; i < n; i++) {
    while (ans.size() >= 2 &&
           orientation(ans[ans.size() - 2], ans.back(), points[i]) <= 0) {
      ans.pop_back();
    }
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