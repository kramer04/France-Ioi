#include <iostream>
int main()
{
  int ingredients [10] = {9, 5, 12, 15, 7, 42, 13, 10, 1, 20};
  int prix{0};
  for (int i{0}; i < 10; i++)
  {
    int entree{0};
    std::cin >> entree;
    prix = prix + ingredients [i] * entree;
  }
  
  std::cout << prix << std::endl;
  return 0;
}
