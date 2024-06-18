#include <iostream>
#include <cmath>
int main()
{
  int nbPersonnes{0}, nbFruits;
  std::cin >> nbPersonnes >> nbFruits;
  if (nbFruits % nbPersonnes == 0)
  {
    std::cout << "oui" << std::endl;
  }
  else
  {
    std::cout << "non" << std::endl;
  }
  return 0;
}
