#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <stack>
#include <tuple>
/* const std::array<std::array<int, 2>, 4> mouvement
{
  -1, 0,
  1, 0,
  0, -1,
  0, 1
}; */
const std::array<std::array<int, 2>, 4> mouvement = {{
  {-1, 0},  // Haut
  {1, 0},   // Bas
  {0, -1},  // Gauche
  {0, 1}    // Droite
  }};
int encoder_etat(int x1, int y1, int x2, int y2, int col, int lig)
{
  return ((x1 * lig + y1) * col * lig) + (x2 * lig + y2);
}
void dfs_pile(int col, int lig, std::vector<std::string> &tab, std::vector<bool> &visite)
{
  std::stack<std::tuple<int, int, int, int>> pile;
  int x1_init{0}, y1_init{0}, x2_init{col - 1}, y2_init{lig - 1};
  if (tab[y1_init][x1_init] != tab[y2_init][x2_init])
  {
    std::cout << 0 << '\n';
    return;
  }
  // Marquer l'état initial comme visité avant de l'empiler
  int etat_init{encoder_etat(x1_init, y1_init, x2_init, y2_init, col, lig)};
  visite[etat_init] = true;
  pile.push(std::make_tuple(x1_init, y1_init, x2_init, y2_init));
  while (!pile.empty())
  {
    int x1, y1, x2, y2;
    std::tie(x1, y1, x2, y2) = pile.top();
    pile.pop();
    if (visite[encoder_etat(x2, y2, x1, y1, col, lig)])
    {
      std::cout << 1 << '\n';
      return;
    }
    // Générer les mouvements pour chaque pion
    for (int i{0}; i < 4; i++)
    {
      int nx1{x1 + mouvement[i][0]}, ny1{y1 + mouvement[i][1]};
      if (nx1 >= 0 && nx1 < col && ny1 >= 0 && ny1 < lig)
      {
        for (int j{0}; j < 4; j++)
        {
          int nx2{x2 + mouvement[j][0]}, ny2{y2 + mouvement[j][1]};
          if (nx2 >= 0 && nx2 < col && ny2 >= 0 && ny2 < lig)
          {
            if (tab[ny1][nx1] == tab[ny2][nx2])
            {
              int nouvel_etat = encoder_etat(nx1, ny1, nx2, ny2, col, lig);
              // Avant d'empiler, on vérifie si l'état n'est pas déjà visité
              if (!visite[nouvel_etat])
              {
                visite[nouvel_etat] = true;
                pile.push(std::make_tuple(nx1, ny1, nx2, ny2));
              }
            }
          }
        }
      }
    }
  }
  // Si aucun chemin n'a été trouvé
  std::cout << 0 << '\n';
}
int main()
{
  int l, h;
  std::cin >> l >> h;
  std::cin.ignore();
  std::vector<std::string> grille(h);
  for (int i{0}; i < h; i++)
  {
    getline(std::cin, grille[i]);
  }
  std::vector<bool> visite(l * h * l * h, false);
  dfs_pile(l, h, grille, visite);
  return 0;
}
