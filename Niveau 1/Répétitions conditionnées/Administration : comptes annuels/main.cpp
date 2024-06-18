#include <iostream>
int main()
{
  int nb{0};
  int i{0};
  while (i != -1)
  {
    std::cin >> i;
    if (i != -1)
    {
      nb += i;
    }
  }
  std::cout << nb << std::endl;
  return 0;
}
