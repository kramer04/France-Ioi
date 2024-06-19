#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <tuple>
#include <numeric>
int dfs(const std::vector<std::vector<int>> &graph, int i)
{
  int n = graph.size();
  std::vector<int> visited(n, 0);
  visited [i] = 1;
  std::stack<int> to_visit;
  to_visit.push(i);
  while (!to_visit.empty())
  {
    int u = to_visit.top();
    to_visit.pop();
    for (int v : graph [u])
    {
      if (!visited [v])
      {
        visited [v] = 1;
        to_visit.push(v);
      }
    }
  }
  return std::accumulate(visited.begin(), visited.end(), 0);
}
std::vector<std::vector<int>> buildGraph(const std::vector<std::tuple<int, int, int>> &arbres)
{
  int n = arbres.size();
  std::vector<std::vector<int>> graph(n);
  for (int i {0}; i < n; ++i)
  {
    int xA, yA, rA;
    std::tie(xA, yA, rA) = arbres [i];
    for (int j {0}; j < n; ++j)
    {
      if (i != j)
      {
        int xB, yB, rB;
        std::tie(xB, yB, rB) = arbres [j];
        int dd = (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB);
        if (dd <= rA * rA)
        {
          graph [i].push_back(j);
        }
      }
    }
  }
  return graph;
}
std::pair<std::vector<std::tuple<int, int, int>>, std::vector<int>> capture()
{
  int N, M; // N = nombre d'arbres, M = nombre de questions
  std::cin >> N >> M;
  std::vector<std::tuple<int, int, int>> arbres(N);
  for (int i {0}; i < N; ++i)
  {
    int x, y, r;
    std::cin >> x >> y >> r;
    arbres [i] = std::make_tuple(x, y, r);
  }
  std::vector<int> questions(M);
  for (int i {0}; i < M; ++i)
  {
    std::cin >> questions [i];
  }
  return std::make_pair(arbres, questions);
}
int main()
{
  std::ios::sync_with_stdio(false);
  auto data = capture();
  std::vector<std::tuple<int, int, int>> arbres = data.first;
  std::vector<int> questions = data.second;
  int n = arbres.size();
  std::vector<std::vector<int>> graph = buildGraph(arbres);
  std::vector<int> reponses(n);
  for (int i {0}; i < n; ++i)
  {
    reponses [i] = dfs(graph, i);
  }
  for (int i : questions)
  {
    std::cout << reponses [i] << '\n';
  }
  return 0;
}
