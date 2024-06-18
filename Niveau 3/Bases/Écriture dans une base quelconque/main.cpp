#include <iostream>
#include <vector>
int main()
{
  int entierAConvertir{0}, baseArrivee{0};
  std::cin >> entierAConvertir >> baseArrivee;
  int nbChiffre{0}, tmp{entierAConvertir}, reste{entierAConvertir};
  std::vector<int> division;
  while (tmp > 0)
  {
    division.push_back(0);
    reste = tmp % baseArrivee;
    division [nbChiffre] = reste;
    
    tmp /= baseArrivee;
    
    nbChiffre++;
  }
  if (entierAConvertir == 0)
  {
    nbChiffre = 1;
    std::cout << nbChiffre << "\n";
    std::cout << 0 << " ";
  }
  else
  {
    std::cout << nbChiffre << "\n";
    for (int i{nbChiffre - 1}; i >= 0; i--)
    {
      std::cout << division [i] << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
