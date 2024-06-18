#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int popTotale{0};
  std::cin >> popTotale;
  int i{1},nbTour{1};
  while (i < popTotale)
  {
    i *= 3;
    nbTour++;
  }
  std::cout << nbTour << std::endl;
  return 0;
}
