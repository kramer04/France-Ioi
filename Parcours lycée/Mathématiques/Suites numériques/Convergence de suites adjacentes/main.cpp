#include <iostream>
#include <cmath>

int main()
{
  double a, b, u, v;
  std::cin >> a >> b;

  u = a;
  v = b;

  while (a < b)
  {
    u = (a + b) / 2;
    v = sqrt((a * a + b * b) / 2);
    a = u;
    b = v;
  }

  std::cout << u << '\n';
  return 0;
}
