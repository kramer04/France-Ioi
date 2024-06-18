#include <iostream>
#include <vector>
//#include <array>
//constexpr int N{6};
using Grille = std::vector<std::vector<int>>;
//using Grille = std::array<std::array<int, N>, N>;
int diagonale(Grille &tab, int n, int jeton, int joueur) noexcept;
int ligne_colonne(Grille &tab, int n, int jeton, int joueur) noexcept;
//void affichage(Grille &tab, int l, int c) noexcept;
int main()
{
  /* Grille grille
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  }; */
  /* Grille grille
  {
    0, 0, 2, 0, 1, 0,
    0, 1, 2, 2, 2, 1,
    0, 0, 2, 0, 1, 0,
    0, 0, 2, 0, 0, 0,
    0, 0, 1, 0, 0, 0,
    0, 1, 0, 0, 0, 0
  }; */
  int N{0};
  std::cin >> N;
  Grille grille;
  for (int i{0}; i < N; i++)
  {
     grille.push_back(std::vector<int>(N));
    for (int j{0}; j < N; j++)
    {
      std::cin >> grille [i][j];
    }
  }
  //affichage(grille, N, N);
  int test1{ligne_colonne(grille, N, 5, 1)};
  int test2{diagonale(grille, N, 5, 1)};
  int test3{ligne_colonne(grille, N, 10, 2)};
  int test4{diagonale(grille, N, 10, 2)};
  if (test1 == 0 && test2 == 0 && test3 == 0 && test4 == 0)
    std::cout << 0 << std::endl;
  else if (test1 + test2 + test3 + test4 == 1)
    std::cout << 1 << std::endl;
  else
    std::cout << 2 << std::endl;
  return 0;
}
int diagonale(Grille &tab, int n, int jeton, int joueur) noexcept
{
  for (int k{n - 1}; k >= 4; k--)
  {
    int sommeD1{0};
    for (int i{0}; i <= k; i++)
    {
      if (tab [i][k - i] == 0)
        sommeD1 = 0;
      if (tab [i][k - i] == joueur)
        sommeD1 += tab [i][k - i];
      if (sommeD1 == jeton)
      {
        //std::cout << "sommeD1 -> " << sommeD1 << std::endl;
        return joueur;
      }
    }
    sommeD1 = 0;
  }
  for (int k{1}; k < n - 1; k++)
  {
    int sommeD2{0};
    for (int i{k}; i < n; i++)
    {
      if (tab [i][n - i + k - 1] == 0)
        sommeD2 = 0;
      if (tab [i][n - i + k - 1] == joueur)
        sommeD2 += tab [i][n - i + k - 1];
      if (sommeD2 == jeton)
      {
        //std::cout << "sommeD2 -> " << sommeD2 << std::endl;
        return joueur;
      }
    }
    sommeD2 = 0;
  }
  for (int k{n - 1}; k >= 0; k--)
  {
    int sommeD3{0};
    for (int i{k}; i < n; i++)
    {
      if (tab [i - k][i] == 0)
        sommeD3 = 0;
      if (tab [i - k][i] == joueur)
        sommeD3 += tab [i - k][i];
      if (sommeD3 == jeton)
      {
        //std::cout << "sommeD3 -> " << sommeD3 << std::endl;
        return joueur;
      }
    }
  }
  for (int k{n - 1}; k >= 0; k--)
  {
    int sommeD4{0};
    for (int i{0}; i <= n - 1 - k; i++)
    {
      if (tab [k + i][i] == 0)
        sommeD4 = 0;
      if (tab [k + i][i] == joueur)
        sommeD4 += tab [k + i][i];
      if (sommeD4 == jeton)
      {
        std::cout << "sommeD4 -> " << sommeD4 << std::endl;
        return joueur;
      }
    }
  }
  return 0;
}
int ligne_colonne(Grille &tab, int n, int jeton, int joueur) noexcept
{
  int sommeL{0}, sommeC{0};
  for (int i{0}; i < n; i++)
  {
    for (int j{0}; j < n; j++)
    {
      if (tab [i][j] == 0)
        sommeL = 0;
      if (tab [j][i] == 0)
        sommeC = 0;
      if (tab [i][j] == joueur)
        sommeL += tab [i][j];
      if (tab [j][i] == joueur)
        sommeC += tab [j][i];
      if (sommeL == jeton)
        return joueur;
      if (sommeC == jeton)
        return joueur;
    }
    sommeL = 0;
    sommeC = 0;
  }
  return 0;
}
/* void affichage(Grille &tab, int l, int c) noexcept
{
  std::cout << "------------------\n";
  for (int i{0}; i < l; i++)
  {
    for (int j{0}; j < c; j++)
    {
      std::cout << tab [i][j] << " ";
    }
    std::cout << "\n";
  }
} */
