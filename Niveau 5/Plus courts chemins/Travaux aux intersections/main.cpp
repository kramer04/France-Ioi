//code 3
#include <iostream>
#include <queue>
#include <array>
const int N = 512;
std::array<std::array<int, N>, N> tab;
std::queue<int> Q;
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n, m;
  std::cin >> n >> m; //respectivement le nombre N d'intersections, et le nombre A de sentiers du labyrinthe.
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      tab [i][j] = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i)
    tab [i][i] = 0;
  int a, b, d;
  for (int i = 0; i < m; ++i)
  {
    std::cin >> a >> b >> d; // Le premier entier est le départ du sentier, le second est l'arrivée du sentier, et le troisième donne la longueur de ce sentier.
    tab [a][b] = d;
  }
  //Algorithme de Floyd-Warshall modifié pour chaque journée
  for (int k = 1; k <= n; ++k)
  {
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (tab [i][j] > tab [i][k] + tab [k][j])
          tab [i][j] = tab [i][k] + tab [k][j];
      }
    }
    for (int i = 1; i <= n; ++i)
    {
      if (tab [i][1] != 0x3f3f3f3f)
        std::cout << tab [i][1];
      else
        std::cout << ".";
      for (int j = 2; j <= n; ++j)
      {
        if (tab [i][j] != 0x3f3f3f3f)
          std::cout << "  " << tab [i][j];
        else
          std::cout << "  .";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}
