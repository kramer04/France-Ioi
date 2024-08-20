#include <iostream>

int main()
{
  int nbJours;
  std::cin >> nbJours;

  int introductionNenuphars {0}, productionNenuphars {0}, total{0};
  
  for (int i {1}; i <= nbJours; ++i)
  {
    introductionNenuphars = i + total;
    productionNenuphars = total;
    total = introductionNenuphars + productionNenuphars;
    std::cout << total << '\n';
  }
  return 0;
}
/*
1er jour
introductionNenuphars = 1
productionNenuphars = 0
total = 1
2ème jour
introductionNenuphars = 2 + 1
productionNenuphars = 1
total = 4
3ème jour
introductionNenuphars = 3 + 4
productionNenuphars = 4
total = 11
4ème jour
introductionNenuphars = 4 + 11
productionNenuphars = 11
total = 26
5ème jour
introductionNenuphars = 5 + 26
productionNenuphars = 26
total = 57
*/
