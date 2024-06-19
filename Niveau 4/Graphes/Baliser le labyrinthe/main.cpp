#include <iostream>
#include <vector>
const int N {1005};
std::vector<int> adj [N]; // Liste d'adjacence
bool used [N][N]; // Indique si l'arc (i, j) est utilisé ou non
std::vector<int> circuit; // Stocke le circuit
/* void dfs(int node)
{
  for (size_t i = 0; i < adj [node].size(); i++)
  {
    int next = adj [node][i];
    if (!used [node][next] && !used [next][node])
    {
      used [node][next] = used [next][node] = true;
      dfs(next);
    }
  }
  circuit.push_back(node);
} */
bool dfs(int node)
{
  if (node == 1 && adj->size() > 0)
    return true;
  for (size_t i = 0; i < adj [node].size(); i++)
  {
    int next = adj [node][i];
    if (!used [node][next] && !used [next][node])
    {
      used [node][next] = used [next][node] = true;
      if (dfs(next))
        return true;
    }
  }
  circuit.push_back(node);
  return false;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    std::cin >> u >> v;
    adj [u].push_back(v);
    adj [v].push_back(u);
  }
  // Vérification que tous les noeuds ont un nombre d'arcs pair
  for (int i = 1; i <= n; i++)
  {
    if (adj [i].size() % 2 != 0)
    {
      std::cout << -1 << '\n';
      return 0;
    }
  }
  // Recherche du circuit
  dfs(1);
  //circuit.push_back(1);
  for (int i {(int) circuit.size() - 1}; i >= 0; i--)
    std::cout << circuit [i] << " ";
  std::cout << '\n';
  return 0;
}
