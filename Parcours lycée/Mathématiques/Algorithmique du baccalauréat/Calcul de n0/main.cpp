#include <iostream>
#include <cmath>
int main()
{
  double p;
  std::cin >> p;
  double u {p}, un {-1.0};
  double puissance {std::pow(10, p)};
  while (un < puissance)
  {
    u++;
    un = std::pow(3, u) + u - 1;
  }
  std::cout << u << '\n';
  return 0;
}
