#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int N, K;
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
template <typename T>
T min_f(T count, T max)
{
  return (count < max) ? count : max;
}
// Fonction pour vérifier si la différence de niveau est suffisante pour déterminer un gagnant
bool sup_k(int a, int b)
{
  return abs(a - b) >= K;
}
// Fonction pour simuler les matchs en utilisant l'algorithme de division pour régner
std::vector<int> simulateMatches(std::vector<int> &levels, int start, int end)
{
  if (start == end)
  {
    return {levels [start]};
  }
  int mid = (start + end) / 2;
  std::vector<int> leftWinners = simulateMatches(levels, start, mid);
  std::vector<int> rightWinners = simulateMatches(levels, mid + 1, end);
  std::vector<int> nextRound;
  for (size_t i = 0; i < leftWinners.size(); ++i)
  {
    for (size_t j = 0; j < rightWinners.size(); ++j)
    {
      int level1 = leftWinners [i];
      int level2 = rightWinners [j];
      if (sup_k(level1, level2))
      {
        nextRound.push_back(max_f(level1, level2));
      }
      else
      {
        nextRound.push_back(level1);
        nextRound.push_back(level2);
      }
    }
  }
  // Enlever les doublons
  sort(nextRound.begin(), nextRound.end());
  nextRound.erase(unique(nextRound.begin(), nextRound.end()), nextRound.end());
  return nextRound;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin >> N >> K;
  int numPlayers = 1 << N;  // 2^N joueurs
  std::vector<int> levels(numPlayers);
  // Lire les niveaux des joueurs
  for (int i = 0; i < numPlayers; ++i)
  {
    std::cin >> levels [i];
  }
  // Simuler le tournoi en utilisant l'algorithme de division pour régner
  std::vector<int> finalWinners = simulateMatches(levels, 0, numPlayers - 1);
  // Trouver le niveau du joueur le plus faible parmi les gagnants
  int lowestWinner = *min_element(finalWinners.begin(), finalWinners.end());
  std::cout << lowestWinner << '\n';
  return 0;
}
