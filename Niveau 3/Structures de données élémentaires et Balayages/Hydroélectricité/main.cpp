#include <iostream>
#include <vector>
int main()
{
  std::ios::sync_with_stdio(false);
  int k{0}, n{0}; //K est la longueur de votre centrale hydroélectrique, N est la longueur de la rivière, en mètres
  std::vector<int> c; //C est la force du courant
  int somme{0}, max{0};
  std::cin >> k >> n;
  for (int i{0}; i < n; i++)
  {
    c.push_back(0);
    std::cin >> c [i];
    
    if (i >= k)
    {
      somme = somme - c [i - k] + c [i];
      if (somme > max)
      {
        max = somme;
      }
      //somme = 0;
    }
    else
    {
      somme += c [i];
      if (somme > max)
      {
        max = somme;
        //somme = 0;
      }
    }
    
  }
  std::cout << max << std::endl;
  return 0;
}
