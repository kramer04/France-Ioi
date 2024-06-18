#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int mois{0};
  std::cin >> mois;
  if (mois == 1 || mois == 2 || mois == 3 || mois == 7 || mois == 8 || mois == 9)
  {
    std::cout << 30 << std::endl;
  }
  else if (mois == 4 || mois == 5 || mois == 6 || mois == 10)
  {
    std::cout << 31 << std::endl;
  }
  else
  {
    std::cout << 29 << std::endl;
  }
  return 0;
}
