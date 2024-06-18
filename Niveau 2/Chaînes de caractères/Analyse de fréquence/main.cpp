#include <iostream>
#include <string>
int main()
{
  int nbLignes{0}, nbMots{0}, tailleMax{0};
  std::cin >> nbLignes >> nbMots;
  int nbMot [1000] = {0};
  for (int i{1}; i <= nbLignes; i++)
  {
    for (int j{1}; j <= nbMots; ++j)
    {
      std::string mot{""};
      std::cin >> mot;
      int taille{(int)mot.size()};
      nbMot [taille]++;
      if (taille > tailleMax)
      {
        tailleMax = taille;
      }
    }
  }
  for (int i{0}; i <= tailleMax; ++i)
  {
    if (nbMot [i] != 0)
      std::cout << i << " : " << nbMot [i] << std::endl;
  }
  return 0;
}
