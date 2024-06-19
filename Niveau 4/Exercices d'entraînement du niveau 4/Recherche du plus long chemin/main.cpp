//chemin le plus long
#include <iostream>
#include <array>
std::array<std::array<char, 21>, 21> lab;
std::array<std::array<bool, 21>, 21> vu;
std::array<std::array<int, 2>, 4> dir {0, 1, -1, 0, 1, 0, 0, -1};
int l, c;
//si 2 chemins les plus longs sont égaux en distance parcourue, choisir le chemin qui a l'ordre alphabétique le premier
std::string direction {"ENSO"}, reponse {};
bool valide(int l, int c, int L, int C)
{
  return 0 <= l && l < L && 0 <= c && c < C;
}
void chemin(int x, int y, std::string parcourt)
{
  if (x == l - 1 && y == c - 2)
  {
    if (parcourt.size() > reponse.size())
      reponse = parcourt;
    else if (reponse > parcourt && reponse.size() == parcourt.size())
      reponse = parcourt;
    return;
  }
  for (int i {0}; i < 4; i++)
  {
    {
      int ny = y + dir [i][1];
      int nx = x + dir [i][0];
      if (valide(nx, ny, l, c) && !vu [nx][ny])
      {
        vu [nx][ny] = true;
        chemin(nx, ny, parcourt + direction [i]);
        vu [nx][ny] = false;
      }
    }
  }
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin >> l >> c;
  for (int i {0}; i < l; i++)
  {
    for (int j {0}; j < c; j++)
    {
      std::cin >> lab [i][j];
      if (lab [i][j] == '.')
        vu [i][j] = false;
      else
        vu [i][j] = true;
    }
  }
  reponse = "";
  chemin(1, 0, "");
  std::cout << reponse.size() << '\n' << reponse << '\n';
  return 0;
}
