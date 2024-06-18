#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  std::vector<int> bac1;
  int n0{0}, n1{0}, tmp{0};
  std::cin >> n0;
  for (int i{0}; i < n0; i++)
  {
    std::cin >> tmp;
    bac1.push_back(tmp);
  }
  std::cin >> n1;
  for (int i{0}; i < n1; i++)
  {
    std::cin >> tmp;
    bac1.push_back(tmp);
  }
  std::sort(bac1.begin(), bac1.end());
  auto it = std::adjacent_find(bac1.begin(), bac1.end());
 
  int nb{0};
  while (it != bac1.end())
  {
    auto d = std::distance(bac1.begin(), it);
    it = std::adjacent_find(bac1.begin() + d + 1, bac1.end());
    nb++;
  }
  std::cout << nb << std::endl;
  return 0;
}
