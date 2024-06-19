#include <iostream>
#include <cmath>
#include <algorithm>
const double EPS = 1e-9;
struct Point
{
  double x, y;
  Point(double x = 0, double y = 0): x(x), y(y) {}
  Point operator+(const Point &p) const
  {
    return Point(x + p.x, y + p.y);
  }
  Point operator-(const Point &p) const
  {
    return Point(x - p.x, y - p.y);
  }
  Point operator*(double k) const
  {
    return Point(x * k, y * k);
  }
  double operator*(const Point &p) const
  {
    return x * p.x + y * p.y;
  }
  double operator^(const Point &p) const
  {
    return x * p.y - y * p.x;
  }
};
typedef Point Vector;
bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}
double dist(const Point &A, const Point &B)
{
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
double dist(const Point &P, const Point &A, const Point &B)
{
  Vector u = B - A, v = P - A;
  double t = (u * v) / (u * u);
  if (t < 0) return dist(P, A);
  if (t > 1) return dist(P, B);
  return dist(P, A + u * t);
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  Point controlTower;
  std::cin >> controlTower.x >> controlTower.y >> n;
  double minDist = 1e9;
  Point closestPisteStart, closestPisteEnd;
  while (n--)
  {
    Point start, end;
    std::cin >> start.x >> start.y >> end.x >> end.y;
    double d = dist(controlTower, start, end);
    if (d < minDist)
    {
      minDist = d;
      closestPisteStart = start;
      closestPisteEnd = end;
    }
  }
  std::cout << closestPisteStart.x << " " << closestPisteStart.y << " " << closestPisteEnd.x << " " << closestPisteEnd.y << '\n';
  return 0;
}
