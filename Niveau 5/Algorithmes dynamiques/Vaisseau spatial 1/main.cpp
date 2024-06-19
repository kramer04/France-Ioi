#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // Lire les entrées
  int N, M, P;
  std::cin >> N >> M >> P;
  // Lire la grille de valeurs
  std::vector<std::vector<int>> grid(N, std::vector<int>(M));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      std::cin >> grid [i][j];
    }
  }
  // Tableau pour la programmation dynamique
  std::vector<std::vector<int>> dp(N, std::vector<int>(M, -1000000));
  // Initialisation de la position de départ
  dp [N - 1][P] = 0;
  // Remplissage du tableau dp
  for (int i = N - 2; i >= 0; --i)
  {
    for (int j = 0; j < M; ++j)
    {
      int max_value = dp [i + 1][j];
      if (j > 0) max_value = std::max(max_value, dp [i + 1][j - 1]);
      if (j < M - 1) max_value = std::max(max_value, dp [i + 1][j + 1]);
      dp [i][j] = grid [i][j] + max_value;
    }
  }
  // Trouver le score maximal possible à la ligne supérieure
  int max_score = *std::max_element(dp [0].begin(), dp [0].end());
  // Afficher le score maximal
  std::cout << max_score << std::endl;
  return 0;
}
