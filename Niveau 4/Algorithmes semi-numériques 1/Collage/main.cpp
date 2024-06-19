#include <iostream>
int pgcd(int x, int y)
{
  return (y) ? pgcd(y, x % y) : x;
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int a, b;
  std::cin >> a >> b;
  std::cout << a * b / pgcd(a, b) << '\n';
  return 0;
}
