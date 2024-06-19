#include <iostream>
int factorielle(int a)
{
  return a > 0 ? a * factorielle(a - 1) : 1;
}
int main()
{
  int n, p;
  std::cin >> n >> p;
  std::cout << factorielle(n) / (factorielle(n - p) * factorielle(p)) << '\n';
  return 0;
}
