#include <iostream>
#include <cmath>
int main()
{
  double diametre;
  std::cin >> diametre;
  double perimetre {0.0}, aire {0.0};
  perimetre = M_PI * diametre;
  perimetre = static_cast<int>(std::round(perimetre));
  aire = M_PI * (diametre * diametre) / 4;
  aire = static_cast<int>(std::round(aire));
  
  std::cout << perimetre << '\n' << aire << '\n';
  return 0;
}
