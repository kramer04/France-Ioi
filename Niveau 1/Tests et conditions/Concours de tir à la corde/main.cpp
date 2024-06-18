#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbMembres{0}, equipe1{0}, equipe2{0}, poids1{0}, poids2{0};
  std::cin >> nbMembres;
  
  repeat(nbMembres)
  {
    std::cin >> equipe1;
    std::cin >> equipe2;
    poids1 += equipe1;
    poids2 += equipe2;
  }
  if (poids1 > poids2)
  {
    std::cout << "L'équipe 1 a un avantage "<< std::endl;
  }
  else
  {
    std::cout << "L'équipe 2 a un avantage  "<< std::endl;
  }
  std::cout << "Poids total pour l'équipe 1 : " << poids1 << std::endl;
  std::cout << "Poids total pour l'équipe 2 : " << poids2 << std::endl;
  return 0;
}
