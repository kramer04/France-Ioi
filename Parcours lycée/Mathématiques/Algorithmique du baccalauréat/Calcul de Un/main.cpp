#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
  int n;
  std::cin >> n;
  double s {0.0};
  for (int i {1}; i <= n; ++i)
  {
    s += 1.0 / i;
  }
  s -= log(n);
  std::cout << std::fixed << std::setprecision(6) << s << '\n';
}
