#include <iostream>
#include <vector>
#include <algorithm>
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
/*template <typename T>
T min_f(T count, T max)
{
  return (count < max) ? count : max;
}*/
struct Temp
{
  int tempMin, tempMax, indice;
};
// Tri croissant sur début intervalle
bool compDebutFin(const Temp &tenue1, const Temp &tenue2)
{
  if (tenue1.tempMin != tenue2.tempMin)
    return tenue1.tempMin < tenue2.tempMin;
  if (tenue1.tempMax != tenue2.tempMax)
    return tenue1.tempMax > tenue2.tempMax;
  return tenue1.indice < tenue2.indice;
}
// Tri décroissant sur fin intervalle
bool compFinDebut(const Temp &tenue1, const Temp &tenue2)
{
  if (tenue1.tempMax != tenue2.tempMax)
    return tenue1.tempMax > tenue2.tempMax;
  if (tenue1.tempMin != tenue2.tempMin)
    return tenue1.tempMin < tenue2.tempMin;
  return tenue1.indice < tenue2.indice;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nbManteaux;
  std::cin >> nbManteaux;
  std::vector<Temp> manteau(nbManteaux);
  for (int i {0}; i < nbManteaux; i++)
  {
    std::cin >> manteau [i].tempMin >> manteau [i].tempMax;
    manteau [i].indice = i;
  }
  std::sort(manteau.begin(), manteau.end(), compDebutFin);
  std::vector<int> rangDebut(nbManteaux);
  for (int i {0}; i < nbManteaux; i++)
    rangDebut [manteau [i].indice] = i;
    
  std::sort(manteau.begin(), manteau.end(), compFinDebut);
  std::vector<int> rangFin(nbManteaux);
  for (int i {0}; i < nbManteaux; i++)
    rangFin [manteau [i].indice] = i;
  int maximum {0};
  for (int i {0}; i < nbManteaux; i++)
    maximum = max_f(maximum, nbManteaux - rangFin [i] - rangDebut [i] - 1);
  std::cout << maximum << '\n';
  return 0;
}
