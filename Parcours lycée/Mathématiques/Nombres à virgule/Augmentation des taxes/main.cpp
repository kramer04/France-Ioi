#include <iostream>
#include <cmath>
int main()
{
  double valeurActuelleTaxe{0.0}, nouvelleValeurTaxe{0.0}, prixActuel{0.0}, prixFutur{0.0}, prixHt{0.0};
  std::cin >> valeurActuelleTaxe >> nouvelleValeurTaxe >> prixActuel;
  prixHt = prixActuel / (1 + valeurActuelleTaxe / 100);
  prixFutur = prixHt * (1 + nouvelleValeurTaxe / 100);
  std::cout << (round(prixFutur*100))/100 << std::endl;
  return 0;
}
