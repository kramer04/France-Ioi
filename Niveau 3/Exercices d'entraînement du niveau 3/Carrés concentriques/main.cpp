#include <iostream>
#include <deque>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  size_t nbLettre{0};
  std::string mot{0};
  std::cin >> nbLettre >> mot;
  size_t t{mot.size()};
  size_t t_grille{mot.size() * 2 - 1};
  std::deque<std::string> grille(t_grille);
  for (size_t i{0}; i < t; ++i)
  {
    grille [i].resize(t_grille);
    std::fill(std::begin(grille [i]), std::end(grille [i]), (char)mot [t - 1]);
    grille [t_grille - i - 1] = grille [i];
  }
  size_t k{1};
  while (k < nbLettre)
  {
    for (size_t i{k}; i < t; ++i)
    {
      //grille [i].resize(t_grille);
      std::fill(std::begin(grille [i]) + k, std::end(grille [i]) - k, (char)mot [t - k - 1]);
      grille [t_grille - i - 1] = grille [i];
    }
    k++;
  }
    for (auto d : grille)
    std::cout << d << "\n";
  return 0;
}
