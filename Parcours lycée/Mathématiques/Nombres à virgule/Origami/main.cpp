#include <iostream>
int main()
{
  int pliage{15};
  //std::cin >> pliage;
  double epaisseurTotale{0.011};
  int i{1};
  while (i <= pliage)
  {
    epaisseurTotale = epaisseurTotale * 2;
    i++;
  }
  std::cout << epaisseurTotale << std::endl;
  return 0;
}
