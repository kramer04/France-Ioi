#include <iostream>
#include <array>
#include <vector>
#include <string>
using Grille = std::array<std::vector<std::string>, 2 >;
std::array<std::array<int, 2>, 4> direction
{
  -1, 0,
  0, 1,
  1, 0,
  0, -1
};
bool on(Grille &grid, int iter, int lin, int col, int l, int c)
{
  if ((lin < 0) || (lin >= l) || (col < 0) || (col >= c))
    return false;
  return grid [iter % 2][lin][col] == '#';
}
void erosion(Grille &image, int iter, int l, int c)
{
  for (int i {0}; i < l; i++)
    for (int j {0}; j < c; j++)
    {
      char &car {image [(iter + 1) % 2][i][j]};
      if (on(image, iter, i, j, l, c) && on(image, iter, i - 1, j, l, c) && on(image, iter, i + 1, j, l, c) && on(image, iter, i, j - 1, l, c) && on(image, iter, i, j + 1, l, c))
        car = '#';
      else
        car = '.';
    }
}
void afficher(Grille &image, int l, int nbIter)
{
  for (int i {0}; i < l; i++)
    std::cout << image [nbIter % 2][i] << '\n';
}
int main()
{
  Grille grille;
  //grille [0].push_back("aaaaaa");
  //std::cout << grille [0][0][0] << '\n';
  int L {0}, C {0}, n {0};
  std::cin >> n;
  std::cin >> L >> C;
  std::cin.ignore();
  std::string str;
  for (int i {0}; i < L; i++)
  {
    getline(std::cin, str);
    grille [0].push_back(str);
    grille [1].push_back(str);
  }
  for (int i {0}; i < n; i++)
    erosion(grille, i, L, C);
  afficher(grille, L, n);
  return 0;
}
