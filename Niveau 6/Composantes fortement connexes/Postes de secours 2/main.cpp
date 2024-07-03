//Kosaraju
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
class Graph
{
  public:
  Graph(int n) : adj(n), radj(n), scc_index(n, -1), n(n) {}
  void addEdge(int u, int v)
  {
    adj [u].push_back(v);
    radj [v].push_back(u);
  }
  void findSCCs()
  {
    std::vector<bool> visited(n, false);
    std::stack<int> finishStack;
   
    for (int i = 0; i < n; ++i)
    {
      if (!visited [i])
      {
        dfs1(i, visited, finishStack);
      }
    }
    
    int scc_count = 0;
    visited.assign(n, false);
    while (!finishStack.empty())
    {
      int v = finishStack.top();
      finishStack.pop();
      if (!visited [v])
      {
        dfs2(v, visited, scc_count++);
      }
    }
    
    condensedGraph.resize(scc_count);
    std::vector<int> inDegree(scc_count, 0);
    for (int u = 0; u < n; ++u)
    {
      for (int v : adj [u])
      {
        int scc_u = scc_index [u];
        int scc_v = scc_index [v];
        if (scc_u != scc_v && condensedGraph [scc_u].find(scc_v) == condensedGraph [scc_u].end())
        {
          condensedGraph [scc_u].insert(scc_v);
          inDegree [scc_v]++;
        }
      }
    }
    
    int sourceCount = 0;
    for (int i = 0; i < scc_count; ++i)
    {
      if (inDegree [i] == 0)
      {
        sourceCount++;
      }
    }
    result = sourceCount;
  }
  int getResult() const
  {
    return result;
  }
  private:
  void dfs1(int v, std::vector<bool> &visited, std::stack<int> &finishStack)
  {
    visited [v] = true;
    for (int u : adj [v])
    {
      if (!visited [u])
      {
        dfs1(u, visited, finishStack);
      }
    }
    finishStack.push(v);
  }
  void dfs2(int v, std::vector<bool> &visited, int scc_count)
  {
    visited [v] = true;
    scc_index [v] = scc_count;
    for (int u : radj [v])
    {
      if (!visited [u])
      {
        dfs2(u, visited, scc_count);
      }
    }
  }
  std::vector<std::vector<int>> adj, radj;
  std::vector<std::unordered_set<int>> condensedGraph;
  std::vector<int> scc_index;
  int result;
  int n;
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  Graph graph(N);
  for (int i = 0; i < M; ++i)
  {
    int A, B;
    std::cin >> A >> B;
    graph.addEdge(A - 1, B - 1);
  }
  graph.findSCCs();
  std::cout << graph.getResult() << "\n";
  return 0;
}
