#include <iostream>
#include <vector>
//#include <string>
#include <cmath>
//#include <chrono>
using Chiffre = std::vector<int>;
int enBaseDix(Chiffre &c, int b1, int taille);
Chiffre enBaseN(int c, int b2);
int main()
{
  std::ios::sync_with_stdio(false);
  /*
  B1, B2, et C, respectivement la base de départ, la base d'arrivée et la taille du nombre (en nombre de chiffres) dans la base de départ.
  */
  int b1{0}, b2{0}, c{0};
  std::cin >> b1 >> b2 >> c;
  Chiffre entier;
  for (int i{0}; i < c; ++i)
  {
    entier.push_back(0);
    std::cin >> entier [i];
  }
  
  int nb = enBaseDix(entier, b1, c);
  if (nb == 0)
  {
    std::cout << 0 << std::endl;
  }
  else
  {
    entier = enBaseN(nb, b2);
    for (int i{(int)entier.size() - 1}; i >= 0; --i)
    {
      std::cout << entier [i] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
//transformation de base N en base 10
int enBaseDix(Chiffre &c, int b1, int taille)
{
  int tmp{0};
  for (int i{taille - 1}; i >= 0; --i)
  {
    tmp += c [i] * (int)(pow(b1, (int)(taille - 1 - i)));
  }
  return tmp;
}
//transformation de base 10 en base N
Chiffre enBaseN(int c, int b2)
{
  int nbChiffre{0}, reste{0};
  std::vector<int> division;
  while (c > 0)
  {
    division.push_back(0);
    reste = c % b2;
    division [nbChiffre] = reste;
    c /= b2;
    nbChiffre++;
  }
  return division;
}
