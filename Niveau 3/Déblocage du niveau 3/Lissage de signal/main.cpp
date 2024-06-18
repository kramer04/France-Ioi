#include <iostream>
#include <vector>
#include <cmath>
bool check(std::vector<double> &copie, double &test)
{
  double diffMax {0.0};
  for (size_t i {0}; i < copie.size() - 1; i++)
  {
    diffMax = std::abs(copie [i + 1] - copie [i]);
    if (diffMax > test)
      return false;
  }
  return true;
}
int lissage(std::vector<double> &copie, std::vector<double> &mesure, double &test)
{
  int nbPasse {0};
  while (!check(copie,test))
  {
    for (size_t i {1}; i < mesure.size() - 2; i++)
    {
      copie [i] = (mesure [i - 1] + mesure [i + 1]) / 2.0;
      copie [i + 1] = (mesure [i] + mesure [i + 2]) / 2.0;
    }
    mesure = copie;
    nbPasse++;
  }
  return nbPasse;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  int nbMesures;
  double test;
  std::cin >> nbMesures >> test;
  std::vector<double> mesures(nbMesures), copie(nbMesures);
  for (int i {0}; i < nbMesures; i++)
  {
    std::cin >> mesures [i];
    copie [i] = mesures [i];
  }
  if (nbMesures < 3 || test == 0)
    std::cout << 0 << '\n';
  else
    std::cout << lissage(copie, mesures, test) << '\n';
  return 0;
}
