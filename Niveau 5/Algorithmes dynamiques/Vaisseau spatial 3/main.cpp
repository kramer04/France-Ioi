//code 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M, P;
  std::cin >> N >> M >> P;
  // Vecteurs pour stocker les bonus
  std::vector<int> I(N - 1), V(N - 1);
  // Lecture des bonus
  /* for (int i = 0; i < N - 1; ++i)
  {
    std::cin >> I [i] >> V [i];
  }
  std::reverse(I.begin(), I.end());
  std::reverse(V.begin(), V.end()); */
  for (int i {N - 2}; i >= 0; i--)
    std::cin >> I [i] >> V [i];
  // Tableau pour stocker les scores maximaux atteignables pour chaque colonne
  std::vector<int> dp(M, INT_MIN);
  dp [P] = 0; // Initialisation du score à la colonne de départ
  // Parcours de chaque ligne de bonus
  for (int i = 0; i < N - 1; ++i)
  {
    std::vector<int> new_dp(M, INT_MIN); // Tableau temporaire pour les mises à jour
    // Mise à jour des scores en fonction des déplacements possibles
    for (int j = 0; j < M; ++j)
    {
      if (dp [j] != INT_MIN)
      {
        // Rester dans la même colonne
        new_dp [j] = std::max(new_dp [j], dp [j]);
        // Aller à gauche
        if (j > 0)
        {
          new_dp [j - 1] = std::max(new_dp [j - 1], dp [j]);
        }
        // Aller à droite
        if (j < M - 1)
        {
          new_dp [j + 1] = std::max(new_dp [j + 1], dp [j]);
        }
      }
    }
    // Ajouter le bonus de la ligne courante à la colonne correspondante
    if (I [i] >= 0 && I [i] < M)
    {
      new_dp [I [i]] += V [i];
    }
    // Copier les nouvelles valeurs de scores dans dp
    dp = new_dp;
  }
  // Le résultat maximal sera le maximum de tous les éléments dans dp
  int maxScore = *std::max_element(dp.begin(), dp.end());
  // Affichage du résultat
  std::cout << maxScore << "\n";
  return 0;
}
