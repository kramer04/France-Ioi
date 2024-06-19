#include <iostream>
#include <vector>
#include <algorithm>
struct Seance
{
  int debut;
  int fin;
};
bool compareSeances(const Seance &s1, const Seance &s2)
{
  return s1.fin < s2.fin;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nbSeances;
  std::cin >> nbSeances;
  std::vector<Seance> seances;
  seances.reserve(nbSeances);
  for (int i = 0; i < nbSeances; ++i)
  {
    int debut, fin;
    std::cin >> debut >> fin;
    seances.push_back({debut, fin});
  }
  // Trier les séances par horaire de fin croissant
  std::sort(seances.begin(), seances.end(), compareSeances);
  int nbSpectacles = 0;
  int finDerniereSeance = -1;
  for (const auto &seance : seances)
  {
    // Si l'horaire de début est supérieur à l'horaire de fin de la dernière séance visionnée
    if (seance.debut > finDerniereSeance)
    {
      finDerniereSeance = seance.fin;
      ++nbSpectacles;
    }
  }
  std::cout << nbSpectacles << std::endl;
  return 0;
}
