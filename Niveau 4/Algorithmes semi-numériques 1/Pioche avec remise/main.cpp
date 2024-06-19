#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
  std::ios::sync_with_stdio(false);
  int n {0}, p {0};
  std::cin >> n >> p;
  std::cout << std::setprecision(0) << std::fixed << pow(n,p) << "\n";
  return 0;
}
