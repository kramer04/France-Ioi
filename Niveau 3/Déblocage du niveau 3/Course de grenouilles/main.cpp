#include <iostream>
#include <vector>
#include <algorithm>
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
template <typename T>
T min_f(T count, T max)
{
  return (count < max) ? count : max;
}
struct Saut
{
  int saut, nbFoisEnTete, indice;
};
int main()
{
  std::ios::sync_with_stdio(false);
  int nbGrenouilles, nbTours;
  std::cin >> nbGrenouilles >> nbTours;
  std::vector<Saut> distanceSaut(nbGrenouilles);
  int max {0}, pos{0};
  bool enTete {true};
  for (int i {0}; i < nbTours; i++)
  {
    int ng, dis;
    std::cin >> ng >> dis;
    if (i < nbTours - 1)
    {
      distanceSaut [ng - 1].saut += dis;
      distanceSaut [ng - 1].indice = ng;
      if (distanceSaut [ng - 1].saut < max && !enTete)
      {
        distanceSaut [pos - 1].nbFoisEnTete++;
      }
      else if (distanceSaut [ng - 1].saut > max)
      {
        max = distanceSaut [ng - 1].saut;
        distanceSaut [ng - 1].nbFoisEnTete++;
        enTete = false;
        pos = ng;
      }
      else
        enTete = true;
    }
  }
  int nbFoisEnTete{0}, indice {1};
  for (Saut i : distanceSaut)
  {
    if (nbFoisEnTete < i.nbFoisEnTete)
    {
      nbFoisEnTete = i.nbFoisEnTete;
      indice = i.indice;
    }
  }
  std::cout << indice << '\n';
  return 0;
}
