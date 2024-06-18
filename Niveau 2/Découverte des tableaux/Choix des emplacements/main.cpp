#include <iostream>
int main()
{
  int nbEmplacements{0};
  std::cin >> nbEmplacements;
  int emplacement [1000] = {0};
  int marchand [1000] = {0};
  for (int i{0}; i < nbEmplacements; i++)
  {
    std::cin >> emplacement [i];
    marchand [emplacement [i]] = i;
  }
  //emplacement 0 = marchand 1
  //emplacement 1 = marchand 4
  //emplacement 2 = marchand 0
  for (int i{0}; i < nbEmplacements; i++)
  {
    std::cout << marchand [i] << std::endl;
  }
  return 0;
}
