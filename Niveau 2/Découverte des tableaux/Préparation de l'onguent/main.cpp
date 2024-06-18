#include <iostream>
int main()
{
  int ingredients [10] = {500, 180, 650, 25, 666, 42, 421, 1, 370, 211};
  int entree{0};
  std::cin >> entree;
  std::cout << ingredients [entree] << std::endl;
  return 0;
}
