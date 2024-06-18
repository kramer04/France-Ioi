#include <iostream>
#include <algorithm>
#include <vector>
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
  sort(tableau.begin(), tableau.end());
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
