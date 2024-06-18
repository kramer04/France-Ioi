#include <iostream>
int main()
{
  int nbOperations{0};
  std::cin >> nbOperations;
  int produits [10] = {0,0,0,0,0,0,0,0,0,0};
  for (int i{1}; i <= nbOperations; ++i)
  {
    int numIngredient{0}, quantite{0};
    std::cin >> numIngredient >> quantite;
    produits [numIngredient - 1] += quantite;
  }
  for (int i{0}; i < 10; ++i)
  {
    std::cout << produits [i] << std::endl;
  }
  return 0;
}
