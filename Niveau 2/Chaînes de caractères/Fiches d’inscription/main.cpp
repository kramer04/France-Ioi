#include <iostream>
#include <string>
int main()
{
  int nbPersonnes{0};
  std::cin >> nbPersonnes;
  for (int i{1}; i <= nbPersonnes; ++i)
  {
    std::string nom{""}, prenom{""};
    std::cin >> prenom >> nom;
    std::cout << nom << " " << prenom << std::endl;
  }
  return 0;
}
