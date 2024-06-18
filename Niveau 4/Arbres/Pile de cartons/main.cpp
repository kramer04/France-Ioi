#include <iostream>
#include <vector>
constexpr int maxCartons {100001};
std::vector<int> nCarton [maxCartons];
void cherche(int node);
int main()
{
  std::ios::sync_with_stdio(false);
  int nbCartons {0};
  std::cin >> nbCartons;
  int n {0}, nc {0};
  for (int i {0}; i <= nbCartons; i++)
  {
    std::cin >> n;
    for (int j {0}; j < n; j++)
    {
      std::cin >> nc;
      nCarton [i].push_back(nc);
    }
  }
  cherche(0);
  return 0;
}
void cherche(int node)
{
  if (node)
    std::cout << "A " << node << "\n";
  for (size_t k {0}; k < nCarton [node].size(); k++)
    cherche(nCarton [node][k]);
  if (node)
    std::cout << "R " << node << "\n";
}
