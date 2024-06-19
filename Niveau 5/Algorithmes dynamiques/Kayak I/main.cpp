#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
// Fonction pour effectuer un tri topologique
void topologicalSort(int v, std::vector<bool> &visited, std::stack<int> &Stack, const std::vector<std::vector<std::pair<int, int>>> &adj)
{
  visited [v] = true;
  for (auto &edge : adj [v])
  {
    int u = edge.first;
    if (!visited [u])
    {
      topologicalSort(u, visited, Stack, adj);
    }
  }
  Stack.push(v);
}
// Fonction principale pour trouver le plus long chemin dans un DAG
int longestPath(int nbIntersections, const std::vector<std::vector<std::pair<int, int>>> &adj)
{
  std::stack<int> Stack;
  std::vector<bool> visited(nbIntersections + 1, false);
  // Appliquer le tri topologique à tous les nœuds
  for (int i = 1; i <= nbIntersections; ++i)
  {
    if (!visited [i])
    {
      topologicalSort(i, visited, Stack, adj);
    }
  }
  // Initialiser les distances avec des valeurs très petites
  std::vector<int> dist(nbIntersections + 1, INT_MIN);
  dist [1] = 0;
  // Processus les nœuds dans l'ordre topologique
  while (!Stack.empty())
  {
    int u = Stack.top();
    Stack.pop();
    if (dist [u] != INT_MIN)
    {
      for (auto &edge : adj [u])
      {
        int v = edge.first;
        int weight = edge.second;
        if (dist [v] < dist [u] + weight)
        {
          dist [v] = dist [u] + weight;
        }
      }
    }
  }
  return dist [nbIntersections];
}
int main()
{
  int nbIntersections, nbRuisseaux;
  std::cin >> nbIntersections >> nbRuisseaux;
  std::vector<std::vector<std::pair<int, int>>> adj(nbIntersections + 1);
  for (int i = 0; i < nbRuisseaux; ++i)
  {
    int inter1, inter2, duree;
    std::cin >> inter1 >> inter2 >> duree;
    adj [inter1].emplace_back(inter2, duree);
  }
  int result = longestPath(nbIntersections, adj);
  std::cout << result << std::endl;
  return 0;
}
