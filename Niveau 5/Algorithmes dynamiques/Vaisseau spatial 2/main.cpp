#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <algorithm>
const int N = 2001;
const int M = 51;
const int INF = 0x3f3f3f3f; // Valeur infinie pour l'initialisation
const int DIR = 3;
using paire = std::pair<int, int>; // Alias pour une paire d'entiers
std::array<std::array<int, M>, N> tab; // Tableau 2D pour stocker les valeurs
paire sum[N][M]; // Tableau 2D pour les résultats intermédiaires
std::array<int, DIR> dir = {0, -1, 1}; // Directions possibles
// Fonction pour comparer deux vecteurs d'entiers
bool Compare(std::vector<int> &a, std::vector<int> &b)
{
  for (size_t i {0}; i < b.size(); ++i)
  {
    if (a[i] == 0 && (b[i] == -1 || b[i] == 1))
      return false;
    else if (b[i] == 0 && (a[i] == -1 || a[i] == 1))
      return true;
    else if (b[i] == -1 && a[i] == 1)
      return true;
    else if (a[i] == -1 && b[i] == 1)
      return false;
  }
  return false;
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n, m, s; // Variables pour les dimensions et le point de départ
  std::cin >> n >> m >> s; // Lecture des dimensions et du point de départ
  n--; // Réduction de n pour correspondre à l'index 0-based
  // Lecture des valeurs dans le tableau
  for (int i = n; i >= 0; --i)
    for (int j = 0; j < m; ++j)
      std::cin >> tab[i][j];
  // Initialisation du tableau des résultats intermédiaires
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= m; ++j)
    {
      sum[i][j].first = -INF; // Valeur initiale pour la somme
      sum[i][j].second = 3; // Direction initiale (3 = non définie)
    }
  }
  // Initialisation pour la première ligne du tableau sum
  for (int i = 0; i < DIR; ++i)
  {
    if (s + dir[i] >= 0 && s + dir[i] < m)
    {
      sum[1][s + dir[i]].first = tab[1][s + dir[i]];
      sum[1][s + dir[i]].second = dir[i];
    }
  }
  // Calcul des valeurs maximales pour chaque case dans le tableau sum
  for (int i {1}; i <= n - 1; ++i)
  {
    for (int j {0}; j < m; ++j)
    {
      if (sum[i][j].first != -INF)
      {
        for (int k {0}; k < DIR; ++k)
        {
          if (j + dir[k] >= 0 && j + dir[k] < m)
          {
            if (sum[i + 1][j + dir[k]].first < sum[i][j].first + tab[i + 1][j + dir[k]])
            {
              sum[i + 1][j + dir[k]].first = sum[i][j].first + tab[i + 1][j + dir[k]];
              sum[i + 1][j + dir[k]].second = dir[k];
            }
            else if (sum[i + 1][j + dir[k]].first == sum[i][j].first + tab[i + 1][j + dir[k]])
            {
              if (dir[k] == 0)
                sum[i + 1][j + dir[k]].second = 0;
              else if (sum[i + 1][j + dir[k]].second != 0)
                sum[i + 1][j + dir[k]].second = 1;
            }
          }
        }
      }
    }
  }
  // Recherche du maximum dans la dernière ligne du tableau sum
  int maximum = -INF;
  std::vector<int> positions;
  for (int i {0}; i < m; ++i)
  {
    if (maximum < sum[n][i].first)
    {
      maximum = sum[n][i].first;
      positions.clear();
      positions.push_back(i);
    }
    else if (maximum == sum[n][i].first)
    {
      positions.push_back(i);
    }
  }
  // Reconstruction de la meilleure séquence à partir des résultats
  std::vector<int> ans;
  for (size_t i {0}; i < positions.size(); ++i)
  {
    int pos = positions[i];
    std::vector<int> aux;
    for (int j = n; j > 0; --j)
    {
      aux.push_back(sum[j][pos].second);
      pos -= sum[j][pos].second;
    }
    std::reverse(aux.begin(), aux.end());
    if (!i || Compare(ans, aux))
      ans = aux;
  }
  // Affichage du résultat final
  for (size_t i {0}; i < ans.size(); ++i)
  {
    if (i)
      std::cout << " " << ans[i];
    else
      std::cout << ans[i];
  }
  return 0;
}
