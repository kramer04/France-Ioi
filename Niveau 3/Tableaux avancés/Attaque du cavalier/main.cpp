#include <iostream>
#include <array>
constexpr int N{8};
using Grille = std::array<std::array<char, N>, N>;
//void affichage(Grille &tab, int l, int c) noexcept;
bool deplacement_cavalier(Grille &tab, int l, int c) noexcept;
bool piece_adverse(Grille &tab, int l, int c) noexcept;
int main()
{
  /* Grille grille
  {
    't','c','.','d','r','f','.','t',
    'p','p','p','.','p','p','p','p',
    '.','.','.','p','.','.','.','c',
    '.','.','.','.','.','f','.','.',
    '.','.','.','.','.','P','.','.',
    '.','C','P','.','D','.','P','.',
    'P','P','.','.','.','.','.','P',
    'T','.','F','.','R','F','.','T'
  };
 */
  Grille grille;
  for (int i{0}; i < N; i++)
  {
    for (int j{0}; j < N; j++)
    {
      std::cin >> grille [i][j];
    }
  }
  //affichage(grille, N, N);
  if (deplacement_cavalier(grille, N, N))
    std::cout << "yes\n";
  else
    std::cout << "no\n";
  
  //affichage(grille, N, N);
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
bool deplacement_cavalier(Grille &tab, int l, int c) noexcept
{
  bool cas1{false}, cas2{false}, cavalier{false};
  int kk{0};
  for (int k{1}; k < 3; k++)
  {
    //trouver le cavalier
    int ligne(0), colonne{0};
    for (int i{0}; i < l; i++)
    {
      for (int j{0}; j < c; j++)
        if (tab [i][j] == 'C')
        {
          ligne = i;
          colonne = j;
          kk++;
          cavalier = true; //std::cout << "ligne -> " << ligne << " colonne -> " << colonne << " kk -> " << kk << std::boolalpha << " cavalier -> " << cavalier << std::endl;
          tab [i][j] = '.';
          break;
        }
      if (cavalier)
        break;
    }
    //std::cout << "69 cavalier -> " << std::boolalpha << cavalier << std::endl;
    //deplacement du cavalier
    //haut
    if (cavalier && ligne - 2 >= 0 && colonne - 1 >= 0)
    {
      //tab [ligne - 2][colonne - 1] = 'C';
      if (piece_adverse(tab, ligne - 2, colonne - 1))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
      //return true;
    }
    if (cavalier && ligne - 2 >= 0 && colonne + 1 < 8)
    {
      //tab [ligne - 2][colonne + 1] = 'C';
      if (piece_adverse(tab, ligne - 2, colonne + 1))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    //gauche
    if (cavalier && ligne - 1 >= 0 && colonne - 2 >= 0)
    {
      //tab [ligne - 1][colonne - 2] = 'C';
      if (piece_adverse(tab, ligne - 1, colonne - 2))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    if (cavalier && ligne + 1 < 8 && colonne - 2 >= 0)
    {
      //tab [ligne + 1][colonne - 2] = 'C';
      if (piece_adverse(tab, ligne + 1, colonne - 2))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    //bas
    if (cavalier && ligne + 2 < 8 && colonne - 1 >= 0)
    {
      //tab [ligne + 2][colonne - 1] = 'C';
      if (piece_adverse(tab, ligne + 2, colonne - 1))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    if (cavalier && ligne + 2 < 8 && colonne + 1 < 8)
    {
      //tab [ligne + 2][colonne + 1] = 'C';
      if (piece_adverse(tab, ligne + 2, colonne + 1))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    //droite
    if (cavalier && ligne - 1 >= 0 && colonne + 2 < 8)
    {
      //tab [ligne - 1][colonne + 2] = 'C';
      if (piece_adverse(tab, ligne - 1, colonne + 2))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    if (cavalier && ligne + 1 < 8 && colonne + 2 < 8)
    {
      //tab [ligne + 1][colonne + 2] = 'C';
      if (piece_adverse(tab, ligne + 1, colonne + 2))
      {
        if (kk == 1)
          cas1 = true;
        if (kk == 2)
          cas2 = true;
      }
        //return true;
    }
    cavalier = false;
  }
  //std::cout << std::boolalpha << "cas1 -> " << cas1 << " cas2 -> " << cas2 << std::endl;
  if (cas1 || cas2)
  {
    //std::cout << std::boolalpha << "cas1 -> " << cas1 << " cas2 -> " << cas2 << std::endl;
    return true;
  }
  
  return false;
}
bool piece_adverse(Grille &tab, int l, int c) noexcept
{
  if (tab [l][c] >= 'a' && tab [l][c] <= 'z')
  {
    return true;
  }
  return false;
}
