#include <iostream>
int factorielle(int a);
int main()
{
  std::ios::sync_with_stdio(false);
  int c;
  std::cin >> c;
  std::cout << factorielle(c) << '\n';
  return 0;
}
int factorielle(int a)
{
  return a > 0 ? a * factorielle(a - 1) : 1;
}
