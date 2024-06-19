#include <iostream>
#include <vector>
//FONCTIONS
std::vector<int>::iterator divide(std::vector<int>::iterator start, std::vector<int>::iterator end);
void quicksort(std::vector<int>::iterator start, std::vector<int>::iterator end);
template <typename Conteneur>
void afficher(Conteneur const &tab);
int main()
{
  std::ios::sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int>tabTri(N);
  for (int i {0}; i < N; i++)
    std::cin >> tabTri [i];
  //afficher(tabTri);
  quicksort(tabTri.begin(), tabTri.end() - 1);
  afficher(tabTri);
  return 0;
}
std::vector<int>::iterator divide(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
  int pivot {*end};
  std::vector<int>::iterator index {start};
  for (std::vector<int>::iterator it {start}; it < end; it++)
  {
    if (*it < pivot)
    {
      int tmp {*it};
      *it = *index;
      *index = tmp;
      index++;
    }
  }
  int tmpo {*end};
  *end = *index;
  *index = tmpo;
  return index;
}
void quicksort(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
  if (start < end)
  {
    std::vector<int>::iterator d = divide(start, end);
    quicksort(start, d - 1);
    quicksort(d + 1, end);
  }
}
template <typename Conteneur>
void afficher(Conteneur const &tab)
{
  for (auto &i : tab)
    std::cout << i << " ";
  std::cout << "\n";
}
// 17
// 12 4 23 1 5 4 17 21 8 3 12 9 31 28 22 16 2
