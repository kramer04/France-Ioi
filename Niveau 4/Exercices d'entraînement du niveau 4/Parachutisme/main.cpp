#include <iostream>
#include <vector>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int D, L, N;
  std::cin >> D >> L >> N;

  // en réprésentation linéaire
  std::vector<int> map(D * D, 0);

  // Lire les lacs et marquer les départs et les arrivées sur la carte
  for (int i = 0; i < L; ++i)
  {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    for (int r = r1; r <= r2; ++r)
    {
      map [r * D + c1] += 1;
      if (c2 + 1 < D)
      {
        map [r * D + c2 + 1] -= 1;
      }
    }
  }

  // Application de la technique du tableau de différences pour obtenir la carte finale
  for (int r = 0; r < D; ++r)
  {
    int running_sum = 0;
    for (int c = 0; c < D; ++c)
    {
      running_sum += map [r * D + c];
      map [r * D + c] = running_sum;
    }
  }

  // Lecture des points et sortie des résultats
  for (int i = 0; i < N; ++i)
  {
    int x, y;
    std::cin >> x >> y;
    if (map [x * D + y] > 0)
    {
      std::cout << "1\n";
    }
    else
    {
      std::cout << "0\n";
    }
  }

  return 0;
}
