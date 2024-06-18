#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbKarvas{0}, poids{0}, age{0}, cornes{0}, garrot{0}, score{0};
  //int poids1{0}, age1{0}, cornes1{0}, garrot1{0}, score1{0};
  std::cin >> nbKarvas;
repeat(nbKarvas)
{
    std::cin >> poids >> age >> cornes >> garrot;
    //std::cin >> poids1 >> age1 >> cornes1 >> garrot1;
    score = cornes * garrot + poids;
    //score1 = cornes1 * garrot1 + poids1;
    std::cout << score << std::endl;
    //std::cout << score1 << std::endl;
}  
  return 0;
}
