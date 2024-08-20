#include <iostream>
#include <cmath>
const double PI = 3.14159265358979323846;
int main()
{
  double d1, d2, densite {0.0};
  int population;
  std::cin >> d1 >> d2 >> population;
  densite = population / (d2 * d2 * PI - d1 * d1 * PI);
  densite = round(densite * 100.0) / 100.0;
  std::cout << densite << '\n';
}
