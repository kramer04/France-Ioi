#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
double distance(double x1, double y1, double x2, double y2)
{
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
int main()
{
  double x1{0.0}, y1{0.0}, x2{0.0}, y2{0.0};
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cout << std::fixed << std::setprecision(6) << distance(x1, y1, x2, y2) << std::endl;
  return 0;
}
