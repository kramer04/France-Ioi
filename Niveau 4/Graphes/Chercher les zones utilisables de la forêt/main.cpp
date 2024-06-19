#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
struct Node
{
  int j;
};
std::vector<Node> node [1005];
std::vector<std::vector<int>> d(1005, std::vector<int>(1005, 0));
std::vector<bool> used(1005, false);
void dfs(int &sum, int const u);
int main()
{
  std::ios::sync_with_stdio(false);
  int n, a; //n et a, respectivement le nombre d'intersections, et de sentiers de la forêt.
  std::cin >> n >> a;
  //std::vector<std::vector<int>> d [a][n];
  
  for (int i {0}; i < a; i++)
  {
    int b, c, e;
    std::cin >> b >> c >> e;
    node[b].push_back({c});
    node [c].push_back({b});
    //d [b][c].push_back(std::vector<int>(e));
    //d [c][b].push_back(std::vector<int>(e));
    d [b][c] = e;
    d [c][b] = e;
  }
  int sum {0}, t {0}, ans{0};
  for (int i {0}; i < n; i++)
  {
    if (!used [i])
    {
      ans++;
      sum = 0;
      dfs(sum, i);
      t = std::max(t, sum);
    }
  }
  std::cout << ans-1 << " " << t << '\n';
  return 0;
}
void dfs(int &sum, int const u)
{
  used [u] = true;
  auto t = node[u].size();
  sum++;
  for (size_t j {0}; j < t; j++)
  {
    int v = node [u][j].j;
    if (!used [v])
      dfs(sum, v);
  }
}
