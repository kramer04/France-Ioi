#include <iostream>
int main()
{
  int n;
  std::cin >> n;
  std::cout << n << '\n';
  while (n != 1)
  {
    if (n % 2)
    {
      n = n * 3 + 1;
      std::cout << n << '\n';
    }
    else
    {
      n /= 2;
      std::cout << n << '\n';
    }
  }
  return 0;
}
