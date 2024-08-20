#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
  int n, resultat {2};
  std::cin >> n;
  for (int i {0}; i < n; i++)
  {
    std::cout << std::fixed << std::setprecision(0) << std::pow(resultat, i) << '\n';
  }
  return 0;
}
