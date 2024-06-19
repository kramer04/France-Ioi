#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int N;
  std::cin >> N;
  std::vector<int> cards(N);
  cards [0] = N;
  for (int i = 1; i < N; ++i)
  {
    cards [i] = i;
  }
  std::vector<std::pair<int, int>> first_step;
  std::vector<std::pair<int, int>> second_step;
  // Première étape: Préparer les cartes en réduisant le désordre
  for (int i = 0; i < N / 2; ++i)
  {
    int pos1 = i + 1;
    int pos2 = N - i;
    first_step.push_back({pos1, pos2});
    std::swap(cards [pos1 - 1], cards [pos2 - 1]);
  }
  // Seconde étape: Finaliser l'ordre
  for (int i = 0; i < N; ++i)
  {
    if (cards [i] != i + 1)
    {
      for (int j = i + 1; j < N; ++j)
      {
        if (cards [j] == i + 1)
        {
          second_step.push_back({i + 1, j + 1});
          std::swap(cards [i], cards [j]);
          break;
        }
      }
    }
  }
  // Afficher le résultat
  std::cout << first_step.size() << " " << second_step.size() << '\n';
  for (const auto &s : first_step)
  {
    std::cout << s.first << " " << s.second << '\n';
  }
  for (const auto &s : second_step)
  {
    std::cout << s.first << " " << s.second << '\n';
  }
  return 0;
}
