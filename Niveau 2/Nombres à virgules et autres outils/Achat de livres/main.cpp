#include <iostream>
#include <cmath>
int main()
{
  double somme{0.0}, prix{0.0};
  std::cin >> somme >> prix;
  std::cout << (int)(somme / prix) << std::endl;
  return 0;
}
