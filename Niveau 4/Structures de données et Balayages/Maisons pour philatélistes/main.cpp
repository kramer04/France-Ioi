#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbMaisons {0};
  std::cin >> nbMaisons;
  std::vector<int> distance(nbMaisons);
  for (int i {0}; i < nbMaisons; ++i)
    std::cin >> distance [i];
  std::sort(distance.begin(), distance.end());
  int d {std::abs(distance [0] - distance [1])};
  int min {d};
  for (int i {1}; i < nbMaisons - 1; ++i)
  {
    d = std::abs(distance [i] - distance [i + 1]);
    if (d < min)
      min = d;
  }
  std::cout << min << '\n';
  return 0;
}
