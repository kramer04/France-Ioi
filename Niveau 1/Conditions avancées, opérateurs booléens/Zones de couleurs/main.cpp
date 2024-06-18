#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbJetons{0};
  std::cin >> nbJetons;
  int maxX{90}, maxJ{70};
  for (int i{1}; i <= nbJetons; i++)
  {
    int x{0}, y{0};
    std::cin >> x >> y;
    //rouge
    if (((x >= 15 && x <= 45) || (x >= 60 && x <= 85)) && ((y >= 60 && y <= maxJ)))
    {
      std::cout << "Dans une zone rouge" << std::endl;
    }
    //bleu
    else if (((x >= 10 && x <= 25) && (y >= 10 && y <= 55)) || ((x >= 25 && x <= 50) && ((y >= 10 && y <= 20)||(y >= 45 && y <= 55))) || ((x >= 50 && x <= 85) && (y >= 10 && y <= 55)))
    {
      std::cout << "Dans une zone bleue" << std::endl;
    }
    //extérieur
    else if ((x < 0 || x > maxX) || (y < 0 || y > maxJ))
    {
      std::cout << "En dehors de la feuille" << std::endl;
    }
    //jaune
    else
    {
      std::cout << "Dans une zone jaune" << std::endl;
    }
  }
  return 0;
}
