// code 2
#include <iostream>
#include <array>
const int N {1024};
std::array<int, N> pre;
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  int n, m, a, b;
  std::cin >> n >> m; // n est le nombre total de travailleurs, m est est le nombre de paires (attaquant,cible) données.
  for (int i = 0; i < n; ++i)
  {
    pre [i] = i;
  }
  for (int i = 0; i < m; ++i)
  {
    /*Chacune des m lignes suivantes contient deux entiers séparés par des espaces.
    Si les deux numéros sont identiques, cela signifie que l'on demande l'affichage de la hiérarchie de ce travailleur.
    Si les deux numéros sont distincts, cela signifie que la société du premier travailleur rachète la société du second travailleur (sauf s'ils sont déjà dans la même société, auquel cas il n'y a rien à faire). */
    std::cin >> a >> b;
    if (a == b)
    {
      std::cout << b;
      while (b != pre [b])
      {
        std::cout << " " << pre [b];
        b = pre [b];
      }
      std::cout << "\n";
    }
    else
    {
      int ka = a;
      int kb = b;
      while (ka != pre [ka]) ka = pre [ka];
      while (kb != pre [kb]) kb = pre [kb];
      if (ka != kb)
        pre [kb] = ka;
    }
  }
  return 0;
}
