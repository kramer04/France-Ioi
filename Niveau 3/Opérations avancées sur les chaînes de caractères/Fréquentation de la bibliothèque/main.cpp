#include <iostream>
int main()
{
  std::ios::sync_with_stdio(false);
  int nb{0},somme{0};
  while (!std::cin.fail())
  {
     somme += nb;
    std::cin >> nb;
  }
  std::cout << somme << std::endl;
  return 0;
}
