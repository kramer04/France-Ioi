#include <iostream>
#include <vector>
constexpr int N = 8;
char symbol {'a' - 1};
// Fonction pour afficher la grille
void afficherGrille(const std::vector<std::vector<char>> &grille)
{
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      std::cout << grille [i][j];
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
//Placer le triomino aux coordonnées données
void place(std::vector<std::vector<char>> &grille, int x1, int y1, int x2, int y2, int x3, int y3)
{
  symbol++;
  grille [x1][y1] = symbol;
  grille [x2][y2] = symbol;
  grille [x3][y3] = symbol;
}
void trimino(std::vector<std::vector<char>> &grille, int n, int x, int y)
{
  if (n == 2)
  {
    symbol++;
    for (int i {0}; i < n; i++)
    {
      for (int j {0}; j < n; j++)
      {
        if (grille [i + x][j + y] == '.')
        {
          grille [i + x][j + y] = symbol;
        }
      }
    }
    return;
  }
  //va chercher la case remplie dans les sub division du carré
  int cx {0}, cy {0};
  for (int i {x}; i < x + n; i++)
  {
    for (int j {y}; j < y + n; j++)
    {
      if (grille [i][j] != '.')
      {
        cx = i;
        cy = j;
      }
    }
  }
  // si le trimino manque dans le 1er quart
  if (cx < x + n / 2 && cy < y + n / 2)
    place(grille, x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2);
  // Si le trimino manquant est dans le 3e quart
  else if (cx >= x + n / 2 && cy < y + n / 2)
    place(grille, x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
  // Si le trimino manquant est dans le 2e quart
  else if (cx < x + n / 2 && cy >= y + n / 2)
    place(grille, x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
  // Si le trimino manquant est dans le 4e quart
  else if (cx >= x + n / 2 && cy >= y + n / 2)
    place(grille, x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);
  //divise les quarts un fois de plus
  trimino(grille, n / 2, x, y + n / 2);
  trimino(grille, n / 2, x, y);
  trimino(grille, n / 2, x + n / 2, y);
  trimino(grille, n / 2, x + n / 2, y + n / 2);
  return;
}
int main()
{
  std::ios::sync_with_stdio(false);
  // Initialiser la grille
  std::vector<std::vector<char>> grille(8, std::vector<char>(8, '.'));
  int goldX, goldY;
  std::cin >> goldX >> goldY;
  // Placer la pièce d'or dans la grille
  grille [goldX][goldY] = '#';
  trimino(grille, N, 0, 0);
  afficherGrille(grille);
  return 0;
}
