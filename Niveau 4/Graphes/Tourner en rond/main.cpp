#include <iostream>
#include <vector>
std::vector<std::vector<int>> graph(1005);
std::vector<bool> vu(1005, false);
bool dfs(int n, int parent);
int main()
{
  std::ios::sync_with_stdio(false);
  int n, a;
  std::cin >> n >> a;
  //std::vector<std::vector<int>> graph(a);
  //std::vector<bool> vu(a, false);
  for (int i = 0; i < a; i++)
  {
    int x, y;
    std::cin >> x >> y;
    graph [x].push_back(y);
    //graph [y].push_back(x);
  }
  for (int i {1}; i <= n; i++)
  {
    for (int j {1}; j <= n; j++)
      vu [j] = false;
    
    if (dfs(i, -1))
    {
      std::cout << "OUI" << std::endl;
      return 0;
    }
  }
  std::cout << "NON" << std::endl;
  return 0;
}
bool dfs(int n, int parent)
{
  vu [n] = true;
  for (size_t i {0}; i < graph [n].size(); i++)
  {
    int next = graph [n][i];
    if (vu [next])
    {
      if (next != parent)
        return true;
    }
    else if (dfs(next, n))
      return true;
    if (graph [i].empty())
      return false;
  }
  return false;
}
