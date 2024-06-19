#include <iostream>
#include <cmath>
int aire(double ax, double ay, double bx, double by, double cx, double cy);
int main()
{
  std::ios::sync_with_stdio(false);
  double ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> cx >> cy;
  std::cout << aire(ax, ay, bx, by, cx, cy) << '\n';
  return 0;
}
int aire(double ax, double ay, double bx, double by, double cx, double cy)
{
  double dab = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
  double dbc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
  double dca = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
  double perimetre = dab + dbc + dca;
  double s = perimetre / 2;
  double aire2 = s * (s - dab) * (s - dbc) * (s - dca);
  double aire = sqrt(aire2);
  return (int)(aire * 2 + 0.5);
}
