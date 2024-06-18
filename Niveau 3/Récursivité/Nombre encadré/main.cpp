#include <iostream>
#include <vector>
#include <algorithm>
void ajout(int nbC);
void ajout1(int nbC);
int main()
{
  int nbCrochet{0}, nb{0};
  std::cin >> nb >> nbCrochet;
  ajout(nbCrochet);
  std::cout << nb;
  ajout1(nbCrochet);
  std::cout << std::endl;
  return 0;
}
void ajout(int nbC)
{
  if (nbC > 0)
  {
    ajout(nbC - 1);
    std::cout << '[';
  }
}
void ajout1(int nbC)
{
  if (nbC > 0)
  {
    ajout1(nbC - 1);
    std::cout << ']';
  }
}
