// quicksort
// code 1
#include <iostream>
#include <vector>
// Fonctions
int partition(std::vector<int> &tab, int debut, int fin);
void quick_sort(std::vector<int> &tab, int debut, int fin);
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int>tab(n);
  //size_t taille {tab.size()};
  for (int i {0}; i < n; i++)
    std::cin >> tab [i];
  quick_sort(tab, 0, n - 1);
  //std::cout << "Tableau trié\n";
  for (int i : tab)
    std::cout << i << " ";
  std::cout << '\n';
  return 0;
}
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
