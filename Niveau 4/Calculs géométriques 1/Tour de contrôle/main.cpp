#include <iostream>
#include <cmath>
#include <stack>
template <typename T>
T min(T a, T b);
struct Point
{
  int x, y;
  double d;
};
int main()
{
  std::ios::sync_with_stdio(false);
  int x, y;
  std::cin >> x >> y;
  int nbm;
  double d {0.0};
  std::cin >> nbm;
  std::stack<Point> point;
  int ax, by;
  std::cin >> ax >> by;
  d = sqrt(pow(ax - x, 2) + pow(by - y, 2));
  point.push({ax, by, d});
  for (int i {2}; i <= nbm; i++)
  {
    std::cin >> ax >> by;
    d = sqrt(pow(ax - x, 2) + pow(by - y, 2));
    if (d < point.top().d)
      point.push({ax, by, d});
  }
  std::cout << point.top().x << " " << point.top().y << '\n';
  return 0;
}
template <typename T>
T min(T a, T b)
{
  if (a < b)
    return a;
  return b;
}
