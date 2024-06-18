#include <iostream>
int main()
{
  int nbProduits{0}, nbPersonnes{0};
  std::cin >> nbProduits >> nbPersonnes;
  int nbTotalProduits [1000] = {0};
  for (int i{1}; i <= nbPersonnes; i++)
  {
    int nb{0};
    std::cin >> nb;
    nbTotalProduits [nb]++;
  }
  for (int i{0}; i < nbProduits; ++i)
  {
    std::cout << nbTotalProduits [i] << std::endl;
  }
  return 0;
}
