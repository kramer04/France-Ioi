#include <iostream>
#include <algorithm>
#include <vector>
// Fonctions
int partition(std::vector<int> &tab, int low, int high);
void quick_sort(std::vector<int> &tab, int low, int high);
int main()
{
  std::ios::sync_with_stdio(false);
  int nb{0};
  std::cin >> nb;
  std::vector<int> tableau(nb);
  int nb_negatif{0};
  for (int i{0}; i < nb; ++i)
  {
    std::cin >> tableau [i];
    if (tableau [i] < 0)
      nb_negatif++;
  }
  //sort(tableau.begin(), tableau.end());
  quick_sort(tableau, 0, nb - 1);
  int nbx{0};
  auto result = std::find(std::begin(tableau), std::end(tableau), -tableau[0]);
  
  if (result != std::end(tableau))nbx++;
  for (int i{1}; i < nb_negatif; ++i)
  {
    if (tableau [i - 1] != tableau [i])
    {
      result = std::find(std::begin(tableau) + i, std::end(tableau), -tableau[i]);
      if (result != std::end(tableau))nbx++;
    }
  }
  std::cout << nbx << std::endl;
  
  return 0;
}
int partition(std::vector<int> &tab, int low, int high)
{
  // choix du pivot
  int pivot {tab [high]};
  // Index du plus petit élément et indiquer
  // la bonne position de pivot trouvée jusqu'à présent
  int index {low - 1};
  for (int i {low}; i <= high; i++)
  {
    // Si l'élément actuel est plus petit que le pivot
    if (tab [i] < pivot)
    {
      index++;
      std::swap(tab [index], tab [i]);
    }
  }
  std::swap(tab [index + 1], tab [high]);
  return index + 1;
}
void quick_sort(std::vector<int> &tab, int low, int high)
{
  // si low est plus petit que high
  if (low < high)
  {
    // pivot est l'index de la partition du pivot
    int pivot {partition(tab, low, high)};
    // Appel récursif
    // L'élément plus petit que le pivot va à gauche et
    // l'élément supérieur va à droite
    quick_sort(tab, low, pivot - 1);
    quick_sort(tab, pivot + 1, high);
  }
}
