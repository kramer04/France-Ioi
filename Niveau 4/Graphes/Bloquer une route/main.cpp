#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
const int MAXN = 1005;
int n, m, ct, cnt, dfn [MAXN], low [MAXN];
std::deque<int> g [MAXN];
std::deque<std::pair<int, int>> close;
void tarjan(int u, int fa)
{
  dfn [u] = low [u] = ++cnt;
  for (size_t i {0}; i < g [u].size(); i++)
  {
    int v = g [u][i];
    if (!dfn [v])
    {
      tarjan(v, u);
      low [u] = std::min(low [u], low [v]);
      if (dfn [u] < low [v])
      {
        //std::cout << u << " " << v << std::endl;
        close.push_front({u, v});
        ct++;
      }
    }
    else if (v != fa)
      low [u] = std::min(low [u], dfn [v]);
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i {1}; i <= m; i++)
  {
    int u, v;
    std::cin >> u >> v;
    g [u].push_back(v);
    g [v].push_back(u);
  }
  tarjan(1, -1);
  std::cout << ct << '\n';
  std::sort(close.begin(), close.end());
  for (auto n : close)
    std::cout << n.first << " " << n.second << '\n';
  return 0;
}
