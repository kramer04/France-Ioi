#include <array>
#include <iostream>
#include <vector>
std::array<std::array<int, 2>, 4> const dir
{
  0, -1,
    0, 1,
    -1, 0,
    1, 0
};
bool trouve = false;
bool dansPlateau(int const lin, int const col, int const l, int const c) noexcept
{
  return ((lin >= 0) && (lin < l) && (col >= 0) && (col < c));
}
void cherche(std::vector<std::string> &grille, std::vector<std::vector<std::vector<std::vector<bool>>>> &vu, int const L, int const C, int a, int b, int c, int d)
{
  if (trouve)
    return;
  if (!dansPlateau(a, b, L, C) || !dansPlateau(c, d, L, C))
    return;
  if (grille [a][b] != grille [c][d])
    return;
  if (vu [a][b][c][d])
    return;
  vu [a][b][c][d] = true;
  if (a == 0 && b == 0 && c == L - 1 && d == C - 1)
  {
    trouve = true;
    return;
  }
  for (int j {0}; j < 4; j++)
  {
    for (int k {0}; k < 4; k++)
    {
      cherche(grille, vu, L, C, a + dir [j][0], b + dir [j][1], c + dir [k][0], d + dir [k][1]);
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int C, L;
  std::cin >> C >> L;
  std::cin.ignore();
  std::vector<std::string> grille(L);
  for (int i {0}; i < L; i++)
    getline(std::cin, grille [i]);
  //std::vector<std::vector<bool>> vu(nbLignes, std::vector<bool>(nbColonnes, false));
  std::vector<std::vector<std::vector<std::vector<bool>>>> vu(L, std::vector<std::vector<std::vector<bool>>>(C, std::vector<std::vector<bool>>(L, std::vector<bool>(C, false))));
  //std::vector<std::vector<std::vector<std::vector<bool>>>> vu(nbLignes, std::vector<std::vector<std::vector<bool>>>(nbLignes, std::vector<std::vector<bool>>(nbColonnes, std::vector<bool>(nbColonnes, false))));
  cherche(grille, vu, L, C, L - 1, C - 1, 0, 0);
  if (trouve)
    std::cout << 1 << '\n';
  else
    std::cout << 0 << '\n';
  return 0;
}
