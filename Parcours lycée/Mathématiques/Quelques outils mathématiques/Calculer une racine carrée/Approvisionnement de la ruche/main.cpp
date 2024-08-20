#include <iostream>
#include <cmath>
int main()
{
  int x, y, nbFleurs, posX_fleur, posY_fleur;
  std::cin >> x >> y >> nbFleurs;
  double distance {0.0};
  int compteur {0};
  for (int i {0}; i < nbFleurs; i++)
  {
    std::cin >> posX_fleur >> posY_fleur;
    distance = sqrt((x - posX_fleur) * (x - posX_fleur) + (y - posY_fleur) * (y - posY_fleur));
    if (distance < 1000)
      compteur++;
  }
  std::cout << compteur << '\n';
  return 0;
}
