#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  double distance {sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))};
  std::cout << distance << '\n';
  return 0;
}
