#include <iostream>
#include <string>
void entree(int in)
{
  int mdp{0};
  while (mdp != in)
  {
    std::cout << "Entrez le code :" << std::endl;
    std::cin >> mdp;
  }
}
int main()
{
  entree(4242);
  std::cout << "Premier code bon." << std::endl;
  entree(2121);
  std::cout << "Bravo." << std::endl;
  return 0;
}
