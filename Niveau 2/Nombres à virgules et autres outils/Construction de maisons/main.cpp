#include <iostream>
#include <cmath>
int main()
{
  double cimentNecessaire{0.0};
  std::cin >> cimentNecessaire;
  int combienDeSacs = ceil(cimentNecessaire / 60);
  std::cout << combienDeSacs * 45 << std::endl;
  return 0;
}
