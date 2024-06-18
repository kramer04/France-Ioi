//algorithme recherche avec recherche dichotomique (quick sort and binary search)
#include <iostream>
#include <vector>
#include <algorithm>
int partition(std::vector<int> &tab, int debut, int fin)
{
  // choix du pivot
  int pivot {tab [fin]};
  // Index du plus petit élément et indiquer
  // la bonne position de pivot trouvée jusqu'à présent
  int index {debut - 1};
  for (int i {debut}; i <= fin; i++)
  {
    // Si l'élément actuel est plus petit que le pivot
    if (tab [i] < pivot)
    {
      index++;
      std::swap(tab [index], tab [i]);
    }
  }
  std::swap(tab [index + 1], tab [fin]);
  return index + 1;
}
void quick_sort(std::vector<int> &tab, int debut, int fin)
{
  // si debut est plus petit que fin
  if (debut < fin)
  {
    // pivot est l'index de la partition du pivot
    int pivot {partition(tab, debut, fin)};
    // Appel récursif
    // L'élément plus petit que le pivot va à gauche et
    // l'élément supérieur va à droite
    quick_sort(tab, debut, pivot - 1);
    quick_sort(tab, pivot + 1, fin);
  }
}
int binary_search(std::vector<int> &densite, int valeur)
{
  size_t low {0}, high {densite.size() - 1}, mid {0};
  if (valeur <= densite [low])
    return densite [low];
  else if (valeur >= densite [high])
    return densite [high];
  else if (valeur == densite [(low + high) / 2])
    return densite [(low + high) / 2];
  while (low <= high)
  {
    if (low == high)
      return densite [low];
    if (low + 1 == high)
    {
      if (valeur - densite [low] <= densite [high] - valeur)
        return densite [low];
      else
        return densite [high];
    }
    mid = (low + high) / 2;
    (valeur <= densite [mid]) ? high = mid : low = mid;
  }
  return -1;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nbValeurs;
  std::cin >> nbValeurs;
  std::vector<int> densite(nbValeurs);
  for (int i {0}; i < nbValeurs; i++)
    std::cin >> densite [i];
  //quick_sort(densite, 0, nbValeurs - 1);
  std::sort(densite.begin(), densite.end());
  int question, cible;
  std::cin >> question;
  for (int i {0}; i < question; i++)
  {
    std::cin >> cible;
    int m {binary_search(densite, cible)};
    std::cout << m << '\n';
  }
  return 0;
}
