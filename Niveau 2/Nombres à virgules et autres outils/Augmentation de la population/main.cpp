#include <iostream>
int main()
{
  int populationActuelle{0}, populationFuture{0};
  double evolution{0.0};
  std::cin >> populationActuelle >> evolution;
  populationFuture = populationActuelle * (1 + evolution / 100);
  std::cout << populationFuture << std::endl;
  return 0;
}
