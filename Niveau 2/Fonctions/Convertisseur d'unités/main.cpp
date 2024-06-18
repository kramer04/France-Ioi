#include <iostream>
#include <string>
constexpr double pied{0.3048};
constexpr double livre{0.002205};
int main()
{
  int nbConversion{0};
  std::cin >> nbConversion;
  for (int i{0}; i < nbConversion; i++)
  {
    double metre{0.0};
    char c;
    std::cin >> metre;
    std::cin.ignore();
    std::cin >> c;
    
    switch (c)
    {
    case 'm':
      std::cout << metre / pied << " p" << std::endl;
      break;
    case 'g':
      std::cout << metre * livre << " l" << std::endl;
      break;
    case 'c':
      std::cout << 32 + 1.8*metre << " f" << std::endl;
    default:
      break;
    }
  }
  return 0;
}
