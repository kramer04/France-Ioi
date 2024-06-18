#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbPersonne{0};
  std::cin >> nbPersonne;
  int taille{0}, age{0}, poids{0};
  bool cheval{true}, brun{true};
  bool bt{true}, ba{true}, bp{true};
  for (int i{1}; i <= nbPersonne; i++)
  {
    std::cin >> taille >> age >> poids >> cheval >> brun;
    int resultat{0};
    bt = (taille >= 178 && taille <= 182);
    ba = (age >= 34);
    bp = (poids < 70);
    resultat = bt + ba + bp + !cheval + brun;
    //std::cout << "resultat -> " << resultat << std::endl;
    if (resultat == 5)
    {
      std::cout << "Très probable" << std::endl;
    }
    else if (resultat == 1 || resultat == 2)
    {
      std::cout << "Peu probable" << std::endl;
    }
    else if (resultat == 3 || resultat == 4)
    {
      std::cout << "Probable" << std::endl;
    }
    else
    {
      std::cout << "Impossible" << std::endl;
    }
  }
  return 0;
}
