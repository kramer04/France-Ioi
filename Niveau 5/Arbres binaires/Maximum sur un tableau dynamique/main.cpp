// passe tout juste !
#include <iostream>
//#include <array>
#include <set>
#include <utility>
using paire = std::pair<int, int>;
size_t H; // H taille du tableau max = 2^17
int R; // R est le nombre de requêtes max = 10 ^ 5
int k {0}, valeur {0};
constexpr int n {(1 << 17) + 2};
//std::array <int, n> tab = {0};
int tab [n] = {0};
std::set <paire, std::greater<paire>> tabSet;
int main()
{
  std::ios::sync_with_stdio(false);
  
  std::cin >> H >> R;
  for (int i {0}; i < R; i++)
  {
    std::cin >> k >> valeur;
    auto it = tabSet.find(paire(tab [k], k));
    if (it != tabSet.end())
      tabSet.erase(it);
    tabSet.insert(paire(valeur, k));
    tab [k] = valeur;
    std::cout << tabSet.begin()->first << '\n';
  }
  return 0;
}
