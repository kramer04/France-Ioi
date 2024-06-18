#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbBacs{0};
  std::cin >> nbBacs;
  std::vector<int> bac;
  for (int i{0}; i < nbBacs; i++)
  {
    bac.push_back(0);
    std::cin >> bac [i];
  }
  std::sort(bac.begin(), bac.end());
  for (auto b : bac)
    std::cout << b << " ";
  std::cout << std::endl;
  return 0;
}
