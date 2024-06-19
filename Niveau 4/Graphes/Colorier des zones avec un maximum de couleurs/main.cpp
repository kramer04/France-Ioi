#include <iostream>
#include <array>
#include <vector>
using Grotte = std::vector<std::vector<char>>;
constexpr std::array<std::array<int, 2>, 4> dir
{
  -1, 0,
  0, 1,
  1, 0,
  0, -1
};
bool dansPlateau(int lin, int col, int l, int c);
bool color(Grotte &couleur, std::vector<std::vector<int>> &test, int x, int y, int l, int c, int ct);
int main()
{
  std::ios::sync_with_stdio(false);
  int l, c;
  std::cin >> l >> c;
  Grotte couleur;
  std::vector<std::vector<int>> test;
  for (int i {0}; i < l; ++i)
  {
    couleur.push_back(std::vector<char>(c));
    test.push_back(std::vector<int>(c));
    for (int j {0}; j < c; ++j)
    {
      std::cin >> couleur [i][j];
      test [i][j] = 0;
    }
  }
  int cnt {0};
  for (int i {0}; i < l; ++i)
    for (int j {0}; j < c; ++j)
    {
      if (couleur [i][j] == '.' && test [i][j] == 0)
        if (color(couleur, test, i, j, l, c, 1))
          cnt++;
    }
  std::cout << cnt << '\n';
  return 0;
}
bool dansPlateau(int lin, int col, int l, int c)
{
  return ((lin >= 0) && (lin < l) && (col >= 0) && (col < c));
}
bool color(Grotte &couleur, std::vector<std::vector<int>> &test, int x, int y, int l, int c, int ct)
{
  test [x][y] = ct;
  for (int i {0}; i < 4; i++)
  {
    int nx = x + dir [i][0];
    int ny = y + dir [i][1];
    if (dansPlateau(nx, ny, l, c) && couleur [nx][ny] == '.')
    {
      if (test [nx][ny] == ct)
        return false;
      if (test [nx][ny] == 0 && !color(couleur, test, nx, ny, l, c, 3 - ct))
        return false;
    }
  }
  return true;
}
