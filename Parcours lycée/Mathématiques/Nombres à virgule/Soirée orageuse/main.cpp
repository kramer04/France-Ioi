#include <iostream>
#include <cmath>
int main()
{
  double nbSecondes{0.0};
  std::cin >> nbSecondes;
  
  std::cout << round(nbSecondes*0.34029) << std::endl;
  return 0;
}
