//code 4
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <utility>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  /*
  N est le nombre de roues de la machine à sous.
  S est le nombre de symboles (tous distincts) présents sur une roue.
  E est l'énergie répartie aléatoirement entre les roues lorsque l'on actionne la machine.
  */
  int N, S, E;
  std::cin >> N >> S >> E;
  // 1er int = symbole, 2nd int = énergie dépensée pour un symbole, 3ème int = compte les roues alignées
  std::unordered_map<int, std::tuple<int, int>> symbole(N);
  int max {0};
  for (int i {0}; i < N; i++)
  {
    for (int j {0}; j < S; j++)
    {
      int s;
      std::cin >> s;
    
      symbole [s] = std::make_tuple(j + std::get<0>(symbole [s]), std::get<1>(symbole [s]) + 1);
      if (E >= std::get<0>(symbole [s]))
      {
        max = std::max(max, std::get<1>(symbole [s]));
        if (N > 1 && std::get<1>(symbole[s]) == N && E > std::get<0>(symbole [s]))
        {
          int e {E - std::get<0>(symbole [s])};
          if ((e % S) != 0)
          {
            max--; 
          }
        }
      }
    }
  }
  std::cout << max << '\n';
  return 0;
}
