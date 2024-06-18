#include <iostream>
#include <algorithm>
int main()
{
  int nbEmissions, dureeMax;
  std::cin >> nbEmissions >> dureeMax;
  int emissions [nbEmissions];
  for (int i {0}; i < nbEmissions; i++)
    std::cin >> emissions [i];
  int max {0}, compteur {0}, duree {0};
  for (int i {0}; i < nbEmissions; i++)
  {
    duree += emissions [i];
    compteur++;
    while (duree > dureeMax)
    {
      duree -= emissions [i - compteur + 1];
      compteur--;
    }
    max = std::max(max, compteur);
  }
  std::cout << max << std::endl;
  return 0;
}
