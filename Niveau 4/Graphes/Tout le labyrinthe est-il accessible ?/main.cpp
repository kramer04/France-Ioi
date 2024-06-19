#include <array>
#include <iostream>
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
void cherche(Grotte const &lab, std::vector<std::vector<bool>> &test, int const &l, int const &c, int x, int y);
int main()
{
  std::ios::sync_with_stdio(false);
  int l, c;
  std::cin >> l >> c;
  Grotte lab;
  std::vector<std::vector<bool>> test;
  for (int i {0}; i < l; ++i)
  {
    lab.push_back(std::vector<char>(c));
    test.push_back(std::vector<bool>(c));
    for (int j {0}; j < c; ++j)
    {
      std::cin >> lab [i][j];
      test [i][j] = false;
    }
  }
  int nbc {0};
  cherche(lab, test, l, c, 1, 0);
  for (int i {0}; i < l; i++)
  {
    for (int j {0}; j < c; j++)
    {
      if (!test [i][j] && lab [i][j] == '.')
        nbc++;
    }
  }
  std::cout << nbc << '\n';
}
bool dansPlateau(int lin, int col, int l, int c)
{
  return ((lin >= 0) && (lin < l) && (col >= 0) && (col < c));
}
void cherche(Grotte const &lab, std::vector<std::vector<bool>> &test, int const &l, int const &c, int x, int y)
{
  test [x][y] = true;
  for (int i {0}; i < 4; i++)
  {
    int nx = x + dir [i][0];
    int ny = y + dir [i][1];
    if (dansPlateau(nx, ny, l, c) && !test [nx][ny] && lab [nx][ny] == '.')
      cherche(lab, test, l, c, nx, ny);
  }
}
