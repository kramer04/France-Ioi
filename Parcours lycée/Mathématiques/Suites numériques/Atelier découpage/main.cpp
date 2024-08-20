#include <iostream>
#include <cmath>

int main()
{
  int nbDecoupe;
  std::cin >> nbDecoupe;

  int totalTriangles {0}, decoupe {0};
  std::cout << 0 << '\n';
  for (int i {1}; i <= nbDecoupe; i++)
  {
    decoupe = std::pow(3, i - 1);
    totalTriangles += decoupe;
    std::cout << totalTriangles << '\n';
  }
  return 0;
}
