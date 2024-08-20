#include <iostream>
int main()
{
  int nbLegumes{0};
  std::cin >> nbLegumes;
  double prixKg{0};
  for (int i{1}; i <= nbLegumes; i++)
  {
    double poids{0.0}, age{0.0}, prix{0.0};
    std::cin >> poids >> age >> prix;
    prixKg = prix / poids;
    std::cout << prixKg << std::endl;
  }
  return 0;
}
