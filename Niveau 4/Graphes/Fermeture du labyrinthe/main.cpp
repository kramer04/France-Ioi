//code 5
#include <iostream>
#include <vector>
#include <queue>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A;
  std::cin >> N >> A;

  // Graphes représentés sous forme de listes d'adjacence
  std::vector<std::vector<int>> adj(N + 1);
  std::vector<int> in_degree(N + 1, 0);

  // Lecture des sentiers et construction du graphe
  for (int i = 0; i < A; ++i)
  {
    int u, v;
    std::cin >> u >> v;
    adj [u].push_back(v);
    in_degree [v]++;
  }

  // File pour réaliser le tri topologique (algorithme de Kahn)
  std::queue<int> q;
  for (int i = 1; i <= N; ++i)
  {
    if (in_degree [i] == 0)
    {
      q.push(i);
    }
  }

  std::vector<int> topo_order;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    topo_order.push_back(node);

    for (int neighbor : adj [node])
    {
      in_degree [neighbor]--;
      if (in_degree [neighbor] == 0)
      {
        q.push(neighbor);
      }
    }
  }

  // Vérification si un tri topologique valide a été trouvé
  if ((int)topo_order.size() == N)
  {
    for (int i = 0; i < N; ++i)
    {
      std::cout << topo_order [i];
      if (i < N - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
  else
  {
    std::cout << "-1\n";
  }

  return 0;
}
