#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
struct Television
{
  int height;
  int width;
  bool sold;
  Television(int h, int w) : height(h), width(w), sold(false) {}
};
bool canFulfillOrder(const Television &tv, int requiredHeight, int requiredWidth)
{
  return !tv.sold && tv.height >= requiredHeight && tv.width >= requiredWidth;
}
bool tryMatching(int tvIndex, const std::vector<std::vector<int>> &graph, std::vector<int> &matchR, std::vector<bool> &visited)
{
  for (int i {0}; i < (int) graph [tvIndex].size(); ++i)
  {
    int orderIndex = graph [tvIndex][i];
    if (!visited [orderIndex])
    {
      visited [orderIndex] = true;
      if (matchR [orderIndex] == -1 || tryMatching(matchR [orderIndex], graph, matchR, visited))
      {
        matchR [orderIndex] = tvIndex;
        return true;
      }
    }
  }
  return false;
}
int maximumMatching(const std::vector<std::vector<int>> &graph, int tvCount, int orderCount)
{
  std::vector<int> matchR(orderCount, -1);
  int result = 0;
  for (int i = 0; i < tvCount; ++i)
  {
    std::vector<bool> visited(orderCount, false);
    if (tryMatching(i, graph, matchR, visited))
    {
      result++;
    }
  }
  return result;
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int N; // Nombre d'écrans en stock
  std::cin >> N;
  std::vector<Television> televisions;
  for (int i {0}; i < N; ++i)
  {
    int h, w;
    std::cin >> h >> w;
    televisions.emplace_back(h, w);
  }
  int R; // Nombre de commandes
  std::cin >> R;
  std::vector<std::pair<int, int>> orders(R);
  for (int i {0}; i < R; ++i)
  {
    std::cin >> orders [i].first >> orders [i].second;
  }
  // Construire un graphe biparti représentant la correspondance possible entre les écrans et les commandes
  std::vector<std::vector<int>> graph(N);
  for (int i {0}; i < N; ++i)
  {
    for (int j {0}; j < R; ++j)
    {
      if (canFulfillOrder(televisions [i], orders [j].first, orders [j].second))
      {
        graph [i].push_back(j);
      }
    }
  }
  // Calculer le couplage maximal dans le graphe biparti
  int maxOrders = maximumMatching(graph, N, R);
  std::cout << maxOrders << std::endl;
  return 0;
}
