#include <iostream>
int main()
{
  int nbCharrettess{0};
  double moyenne{0};
  double poidsCharrettes [3000] = {0.0};
  std::cin >> nbCharrettess;
  for (int i{1}; i <= nbCharrettess; i++)
  {
    std::cin >> poidsCharrettes [i - 1];
    moyenne += poidsCharrettes [i - 1];
  }
  moyenne /= nbCharrettess;
  double poidsPlusMoins[3000] = {0.0};
  for (int i{1}; i <= nbCharrettess; i++)
  {
    poidsPlusMoins [i - 1] = moyenne - poidsCharrettes [i - 1];
    std::cout << poidsPlusMoins [i - 1] << std::endl;
  }
  return 0;
}
