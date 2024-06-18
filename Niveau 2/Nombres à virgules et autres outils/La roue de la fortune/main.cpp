#include <iostream>
#include <cmath>
int main()
{
  int nbZone{0}, curseur{0};
  std::cin >> nbZone;
  if (nbZone >= 0)
  {
    curseur = nbZone % 24;
  }
  else
  {
    curseur = nbZone % 24 + 24;
    if (curseur == 24)
      curseur = 0;
  }
  std::cout << curseur << std::endl;
  return 0;
}
