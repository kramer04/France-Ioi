#include <iostream>
#include <vector>
#include <algorithm>
struct Point
{
  int x, y;
  Point(int l = 0, int c = 0):x(l), y(c) {};
  bool operator<(Point const &z) const
  {
    return (x < z.x || (x == z.x && y < z.y));
  }
};
bool operator==(Point const &point1, Point &point2)
{
  return point1.x == point2.x && point1.y == point2.y;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int l {0}, c {0};
  std::cin >> l >> c;
  std::vector<Point> radar1, radar2;
  for (int i {0}; i < l; i++)
  {
    for (int j {0}; j < c; j++)
    {
      int a {0};
      std::cin >> a;
      if (a)
        radar1.push_back({i, j});
    }
  }
  for (int i {0}; i < l; i++)
  {
    for (int j {0}; j < c; j++)
    {
      int a {0};
      std::cin >> a;
      if (a)
        radar2.push_back({i, j});
    }
  }
  size_t nbD1 {radar1.size()}, nbD2 {radar2.size()};
  size_t nbTotal {nbD1 * nbD2};
  std::vector<Point>vecteur(nbTotal);
  std::vector<Point>vTries(nbTotal);
  for (size_t i {0}; i < nbD1; i++)
  {
    for (size_t j {0}; j < nbD2; j++)
    {
      int dx {radar2 [j].x - radar1 [i].x};
      int dy {radar2 [j].y - radar1 [i].y};
      vecteur [i * nbD2 + j] = Point(dx, dy);
      vTries [i * nbD2 + j] = Point(dx, dy);
    }
  }
  std::sort(vTries.begin(), vTries.end());
  int max {0}, cor {0};
  auto vMax = vTries [0];
  auto vCourant = vTries [0];
  
  for (size_t i {0}; i < nbTotal; i++)
  {
    if (vTries [i] == vCourant)
    {
      cor++;
      if (cor > max)
      {
        max = cor;
        vMax = vCourant;
      }
    }
    else
    {
      cor = 1;
      vCourant = vTries [i];
    }
  }
  std::cout << max << '\n';
  for (size_t i {0}; i < nbD1; i++)
  {
    for (size_t j {0}; j < nbD2; j++)
    {
      if (vecteur [i * nbD2 + j] == vMax)
        std::cout << radar2 [j].x + 1 << " " << radar2 [j].y + 1 << '\n';
    }
  }
  return 0;
}
