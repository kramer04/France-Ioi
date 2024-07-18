#include <iostream>
#include <vector>
using Vc = std::vector<std::vector<char>>;
// Constantes de chaîne de caractères pour les couleurs
// Pour avoir une sortie en couleur sur son terminal
/*const char *RESET = "\033[0m";
const char *BLUE = "\033[34m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";
void printGrid(const std::vector<std::vector<char>> &grille, size_t N)
{
  for (size_t x {0}; x < N; x++)
  {
    for (size_t y {0}; y < N; y++)
    {
      switch (grille [x][y])
      {
      case '@':
        std::cout << BLUE << grille [x][y] << RESET;
        break;
      case '*':
        std::cout << RED << grille [x][y] << RESET;
        break;
      case '#':
        std::cout << GREEN << grille [x][y] << RESET;
        break;
      default:
        std::cout << grille [x][y];
        break;
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}*/
void printGrid(const std::vector<std::vector<char>> &grille, int N)
{
  for (int x {0}; x < N; x++)
  {
    for (int y {0}; y < N; y++)
    {
      if (grille [x][y] != '.')
        std::cout << grille [x][y];
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
void diagonale(Vc &grid, int s, int n, int niveau)
{
  //place en diagonale
  int row {1 << (niveau - n)}, col {1 << (niveau - n)};
  for (int i {s / n}; i < s; i++)
  {
    for (int j {0}; j < (s / n); j++)
    {
      if (grid [i][j] != '.')
      {
        //grid [i - niveau + 1][(s / n) - niveau + 1 + j] = grid [i][j];
        grid [row][col] = grid [i][j];
        col++;
      }
    }
    col = 1 << (niveau - n);
    row++;
  }
}
void haut_gauche(Vc &grid, int s, int n)
{
  for (int j {0}; j < (s / n); j++)
  {
    int col {0};
    for (int i {s - 1}; i >= s / n; i--)
    {
      if (grid [i][j] != '.' && grid [j][col] == '.')
      {
        grid [j][col] = grid [i][j];
        col++;
      }
    }
  }
}
void bas_droite(Vc &grid, int s, int n)
{
  int row {0};
  for (int i {s - 1}; i >= s / n; i--)
  {
    for (int j {s / n - 1}; j >= 0; j--)
    {
      if (grid [i][j] != '.' && grid [i - j + row][i] == '.')
      {
        grid [i - j + row][i] = grid [i][j];
      }
    }
    row++;
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  Vc trom1(2, std::vector<char>(2, '.'));
  trom1 [0][0] = '@';
  trom1 [1][0] = '*';
  trom1 [1][1] = '#';
  int size {1 << 2};
  Vc trom2 = {
    {'*', '@', '.', '.'},
    {'#', '@', '.', '.'},
    {'@', '*', '#', '#'},
    {'*', '#', '@', '*'}
  };
  if (n == 1)
    printGrid(trom1, 2);
  else if (n == 2)
    printGrid(trom2, size);
  else
  {
    for (int i {3}; i <= n; i++)
    {
      if (i % 2)
      {
        size = 1 << i;
        trom1.clear();
        trom1.resize(size, std::vector<char>(size, '.'));
        for (int i {size / 2}; i < size; i++)
        {
          for (int j {0}; j < size / 2; j++)
          {
            if (trom2 [i - size / 2][j] != '.')
              trom1 [i][j] = trom2 [i - size / 2][j];
          }
        }
        //printGrid(trom1, size);
        diagonale(trom1, size, 2, i);
        //printGrid(trom1, size);
        haut_gauche(trom1, size, 2);
        //printGrid(trom1, size);
        bas_droite(trom1, size, 2);
        //printGrid(trom1, size);
      }
      else
      {
        size = 1 << i;
        trom2.clear();
        trom2.resize(size, std::vector<char>(size, '.'));
        for (int i {size / 2}; i < size; i++)
        {
          for (int j {0}; j < size / 2; j++)
          {
            if (trom1 [i - size / 2][j] != '.')
              trom2 [i][j] = trom1 [i - size / 2][j];
          }
        }
        //printGrid(trom2, size);
        diagonale(trom2, size, 2, i);
        //printGrid(trom2, size);
        haut_gauche(trom2, size, 2);
        //printGrid(trom2, size);
        bas_droite(trom2, size, 2);
        //printGrid(trom2, size);
      }
    }
    if (n % 2)
      printGrid(trom1, size);
    else
      printGrid(trom2, size);
  }
  return 0;
}
