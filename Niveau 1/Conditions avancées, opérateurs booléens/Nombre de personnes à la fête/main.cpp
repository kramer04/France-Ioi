#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbPersonnes{0}, nbIt{0}, nbMax{0};
  std::cin >> nbPersonnes;
  for (int i{1}; i <= nbPersonnes * 2; ++i)
  {
    int nb{0};
    std::cin >> nb;
    nb > 0 ? nbIt++ : nbIt--;
    if (nbIt >= nbMax)
    {
      nbMax = nbIt;
    }
  }
  std::cout << nbMax << std::endl;
  
  return 0;
}
