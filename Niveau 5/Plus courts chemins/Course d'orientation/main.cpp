//code 1
#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A;
  std::cin >> N >> A;
  std::vector<std::tuple<int, int, int>> edges(A);
  for (int i {0}; i < A; ++i)
  {
    int u, v, t;
    std::cin >> u >> v >> t;
    edges [i] = std::make_tuple(u, v, t);
  }
  std::vector<int> dist(N + 1, INT_MAX);
  dist [1] = 0;
  // Relax edges |V| - 1 times
  for (int i {1}; i < N; ++i)
  {
    for (int j {0}; j < A; ++j)
    {
      int u, v, t;
      std::tie(u, v, t) = edges [j];
      if (dist [u] != INT_MAX && dist [u] + t < dist [v])
      {
        dist [v] = dist [u] + t;
      }
    }
  }
  // Vérification des cycles de poids négatifs
  for (int j {0}; j < A; ++j)
  {
    int u, v, t;
    std::tie(u, v, t) = edges [j];
    if (dist [u] != INT_MAX && dist [u] + t < dist [v])
    {
      std::cout << "ERREUR" << '\n';
      return 0;
    }
  }
  // Donne la distance la plus courte jusqu'au dernier nœud (en supposant que l'index est basé sur 1 et que 1 est le point de départ).
  int result = dist [N];
  if (result == INT_MAX)
  {
    std::cout << "ERREUR" << '\n';
  }
  else
  {
    std::cout << result << '\n';
  }
  return 0;
}
