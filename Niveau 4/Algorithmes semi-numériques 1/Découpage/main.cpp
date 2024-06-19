#include <iostream>
int pgcd(int x, int y)
{
  return (y) ? pgcd(y, x % y) : x;
}
int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << pgcd(a, b) << '\n';
  return 0;
}
