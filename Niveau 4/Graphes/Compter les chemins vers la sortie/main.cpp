#include <iostream>
#include <vector>
#include <array>
using Grotte = std::vector<std::vector<char>>;
std::array<std::array<int, 2>, 4> const direction
{
  0, -1,
  -1, 0,
  0, 1,
  1, 0
};
void cherche(Grotte const &lab, std::vector<std::vector<bool>> &test, int const &l, int const &c, int x, int y, int &nbc);
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
  cherche(lab, test, l, c, 1, 0, nbc);
  std::cout << nbc << '\n';
}
void cherche(Grotte const &lab, std::vector<std::vector<bool>> &test, int const &l, int const &c, int x, int y, int &nbc)
{
  if (x == l - 1 && y == c - 2)
  {
    nbc++;
    return;
  }
  test [x][y] = true;
  if (lab [x][y + direction [2][1]] == '.' && !test [x][y + direction [2][1]])
    cherche(lab, test, l, c, x, y + direction [2][1], nbc);
  if (lab [x + direction [3][0]][y] == '.' && !test [x + direction [3][0]][y])
    cherche(lab, test, l, c, x + direction [3][0], y, nbc);
  if (lab [x][y + direction [0][1]] == '.' && y > 0 && !test [x][y + direction [0][1]])
    cherche(lab, test, l, c, x, y + direction [0][1], nbc);
  if (lab [x + direction [1][0]][y] == '.' && x > 1 && !test [x + direction [1][0]][y])
    cherche(lab, test, l, c, x + direction [1][0], y, nbc);
  test [x][y] = false;
}
