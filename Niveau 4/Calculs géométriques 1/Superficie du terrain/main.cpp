#include <iostream>
int max(int a, int b);
int min(int a, int b);
int calcul(int surface, int x, int y, int x1, int y1, int ax, int ay, int bx, int by);
int main()
{
  std::ios::sync_with_stdio(false);
  int x, y, x1, y1;
  std::cin >> x >> y >> x1 >> y1;
  int surface;
  surface = (y1 - y) * (x1 - x);
  
  int n {0}, ax,ay,bx,by;
  std::cin >> n;
  for (int i {1}; i <= n; i++)
  {
    std::cin >> ax >> ay >> bx >> by;
    surface = calcul(surface, x, y, x1, y1, ax, ay, bx, by);
  }
  
  std::cout << surface << '\n';
}
int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}
int min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}
int calcul(int surface, int x, int y, int x1, int y1, int ax, int ay, int bx, int by)
{
  int minx, maxx, miny, maxy;
  maxx = max(ax, x);
  minx = min(bx, x1);
  maxy = max(ay, y);
  miny = min(by, y1);
  if (maxx <= x1 && minx >= x && maxy <= y1 && miny >= y)
    surface -= (maxx - minx) * (maxy - miny);
  return surface;
}
