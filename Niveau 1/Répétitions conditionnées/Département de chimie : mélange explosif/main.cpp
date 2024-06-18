#include <iostream>
int main()
{
  int nbTotalMesures{0}, tempMin{0}, tempMax{0}, i{1};
  std::cin >> nbTotalMesures >> tempMin >> tempMax;
  while (i <= nbTotalMesures)
  {
    int mesure{0};
    std::cin >> mesure;
    if (mesure < tempMin || mesure > tempMax)
    {
      std::cout << "Alerte !!" << std::endl;
      i = nbTotalMesures;
    }
    else
    {
      std::cout << "Rien à signaler " << std::endl;
    }
    i++;
  }
  return 0;
}
