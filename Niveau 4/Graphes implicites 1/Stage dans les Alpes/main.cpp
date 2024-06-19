#include <iostream>
#include <vector>
void alpes(std::vector<int> &stage, int const k, int const n)
{
  if ((int) stage.size() == n)
  {
    //p.push_back(stage);
    for (int z {0}; z < (int)stage.size(); z++)
    {
      if (z)
      {
        std::cout << " " << stage [z];
      }
      else
        std::cout << stage [z];
    }
    std::cout << '\n';
    return;
  }
  int start {1};
  if (!stage.empty())
    start = stage.back();
  for (int i {start}; i <= k; ++i)
  {
    stage.push_back(i);
    alpes(stage, k, n);
    stage.pop_back();
  }
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int n, k;
  std::cin >> k >> n;
  //std::vector<std::vector<int>> parcours;
  std::vector<int>stage;
  alpes(stage, k, n);
  /* for (size_t i {0}; i < parcours.size(); i++)
  {
    for (size_t j {0}; j < parcours [i].size(); j++)
    {
      std::cout << parcours [i][j] << " ";
    }
    std::cout << '\n';
  } */
  return 0;
}
