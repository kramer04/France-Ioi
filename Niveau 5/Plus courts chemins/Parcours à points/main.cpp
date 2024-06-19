//code 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A, K, T;
  std::cin >> N >> A >> K >> T;
  // Graph representation: adj[i] = liste de (voisin, points) pairs
  std::vector<std::vector<std::pair<int, int>>> adj(N + 1);
  for (int i = 0; i < A; ++i)
  {
    int u, v, points;
    std::cin >> u >> v >> points;
    adj [u].emplace_back(v, points);
  }
  // DP table: dp[t][i] représente le score max au temps t à l'intersection i
  std::vector<std::vector<int>> dp(T + 1, std::vector<int>(N + 1, INT_MIN));
  dp [0][K] = 0; // Démarre à l'intersection K avec 0 points
  // rempli la table DP
  for (int t = 1; t <= T; ++t)
  {
    for (int i = 1; i <= N; ++i)
    {
      if (dp [t - 1][i] != INT_MIN)
      {
        // Reste à la même intersection
        dp [t][i] = std::max(dp [t][i], dp [t - 1][i]);
        // Se déplace à l'intersection adjacente
        for (size_t j = 0; j < adj [i].size(); ++j)
        {
          int next = adj [i][j].first;
          int points = adj [i][j].second;
          dp [t][next] = std::max(dp [t][next], dp [t - 1][i] + points);
        }
      }
    }
  }
  // Cherche le score max possible après T minutes
  int max_score = INT_MIN;
  for (int i = 1; i <= N; ++i)
  {
    max_score = std::max(max_score, dp [T][i]);
  }
  std::cout << max_score << '\n';
  return 0;
}
