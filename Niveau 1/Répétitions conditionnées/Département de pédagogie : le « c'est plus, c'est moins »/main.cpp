#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nb{0};
  std::cin >> nb;
  int i{0}, nbEssai{0};
  while (i != nb)
  {
    std::cin >> i;
    if (i > nb)
    {
      std::cout << "c'est moins" << std::endl;
    }
    if (i < nb)
    {
      std::cout << "c'est plus" << std::endl;
    }
    nbEssai++;
  }
  std::cout << "Nombre d'essais nécessaires :" << std::endl;
  std::cout << nbEssai << std::endl;
  return 0;
}
