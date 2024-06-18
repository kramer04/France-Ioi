#include <iostream>
#include <cmath>
int main()
{
  int baseDepart{2}, nbChiffres{1}, nbc{0}, dix{0};
  std::cin >> baseDepart >> nbChiffres;
  for (int i{nbChiffres - 1}; i >= 0; i--)
  {
    std::cin >> nbc;
    dix += nbc * (int)pow(baseDepart, i);
  }
  std::cout << dix << std::endl;
  return 0;
}
