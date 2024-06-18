#include <iostream>
#include <vector>
#include <utility>
#include <array>
using Grotte = std::vector<std::vector<int>>;
std::array<std::array<int, 2>, 4> direction
{
  0, -1,
  -1, 0,
  0, 1,
  1, 0
};
int compteur{0}, tmp{0};
std::vector<std::pair<int, int>> sortie;
//Fonctions
bool chemin(Grotte &grille, int x, int y, int olddir, int l, int c);
bool dansPlateau(int lin, int col, int l, int c);
int main()
{
  std::ios::sync_with_stdio(false);
  int L{0}, C{0};
  std::cin >> L >> C >> compteur;
  Grotte lab;
  for (int i{0}; i < L; ++i)
  {
    lab.push_back(std::vector<int>(C));
    for (int j{0}; j < C; ++j)
    {
      std::cin >> lab [i][j];
    }
  }
  if (chemin(lab, L - 1, C, 0, L, C))
  {
    for (int i{0}; i < (int)sortie.size(); ++i)
      std::cout << sortie [i].first << " " << sortie [i].second << '\n';
  }
  return 0;
}
bool chemin(Grotte &grille, int x, int y, int olddir, int l, int c)
{
  int nx{0}, ny{0}, i{0};
  if (x == 0 && y == 0)
    return true;
  if (grille [x][y] == 0 || y == c)
  {
    for (; i < 4; ++i)
    {
      if (i != (olddir + 2) % 4)
      {
        nx = x + direction [i][0];
        ny = y + direction [i][1];
        if (dansPlateau(nx, ny, l, c) && chemin(grille, nx, ny, i, l, c))
        {
          tmp++;
          if (tmp == compteur + 1)
          {
            tmp = 0;
            grille [nx][ny] = 7;
            sortie.push_back({nx, ny});
          }
          else
            grille [nx][ny] = 5;
          
          return true;
        }
      }
    }
  }
  return false;
}
bool dansPlateau(int lin, int col, int l, int c)
{
  return ((lin >= 0) && (lin < l) && (col >= 0) && (col < c));
}
