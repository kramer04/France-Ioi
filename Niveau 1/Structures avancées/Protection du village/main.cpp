#include <iostream>
int main()
{
  int x{0}, y{0}, minX{1000000}, minY{1000000}, maxX{0}, maxY{0}, longueur{0}, largeur{0}, perimetre{0};
  int nbMaison{0};
  std::cin >> nbMaison;
  for (int i{1}; i <= nbMaison; i++)
  {
    std::cin >> x >> y;
    if (x > maxX)
    {
      maxX = x;
    }
    if (x < minX)
    {
        minX = x;
    }
    if (y > maxY)
    {
      maxY = y;
    }
    if (y < minY)
    {
      minY = y;
    }
  }
  longueur = maxX - minX;
  largeur = maxY - minY;
  perimetre = (longueur + largeur) * 2;
  std::cout << perimetre << std::endl;
  return 0;
}
