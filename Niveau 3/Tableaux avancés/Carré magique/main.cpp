#include <iostream>
#include <vector>
using Grille = std::vector<std::vector<int>>;

bool isCarreMagic(Grille &tab, int n, int sT);
int main()
{
  int N{0};//nombre de cases du carré
  std::cin >> N;
  int sommeTotale{0};
  sommeTotale = N * (N * N + 1) / 2;// valeur du carré magique
  Grille carre;
  for (int i{0}; i < N; i++)
  {
    carre.push_back(std::vector<int>(N));
    for (int j{0}; j < N; j++)
    {
      std::cin >> carre [i][j];
    }
  }
  
  if (isCarreMagic(carre, N, sommeTotale))
  {
    std::cout << "yes\n";
  }
  else
  {
    std::cout << "no\n";
  }
  return 0;
}
bool isCarreMagic(Grille &tab, int n, int sT)
{
  int test{0};
  for (int i{1}; i <= n * n; i++)
  {
    for (int l{0}; l < n; l++)
    {
      for (int c{0}; c < n; c++)
      {
        if (tab [l][c] == i)
          test ++;
      }
    }
    if (test == 0 || test > 1)
      return false;
    
    test = 0;
  }
  int sommeD1{0}, sommeD2{0};
  for (int i{0}; i < n; i++)
  {
    sommeD1 += tab [i][i];
    sommeD2 += tab [i][n - i - 1];
  }
  if (sommeD1 != sT || sommeD2 != sT)
    return false;
  for (int i{0}; i < n; i++)
  {
    int ligneSomme{0}, colonneSomme{0};
    for (int j{0}; j < n; j++)
    {
      ligneSomme += tab [i][j];
      colonneSomme += tab [j][i];
    }
    if (ligneSomme != sT || colonneSomme != sT)
      return false;
  }
  
  return true;
}
