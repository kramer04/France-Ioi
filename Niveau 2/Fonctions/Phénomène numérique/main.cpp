#include <iostream>
int min2(int x)
{
  if (x % 2 == 0)
  {
    return x /= 2;
  }
  else
  {
    return x = x * 3 + 1;
  }
}
int main()
{
  int terme{0};
  std::cin >> terme;
  while (terme != 1)
  {
    terme = min2(terme);
    std::cout << terme << " ";
  }
  std::cout << std::endl;
  return 0;
}
