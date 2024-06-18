#include <iostream>
#include <string>
void ajout(int nbC, std::string t1, std::string t2);
int main()
{
  int nb{0};
  std::cin >> nb;
  std::string s{"0"}, s1{"0"};
  std::cout << "0 = ";
  if(nb == 0)
    std::cout << "0";
  else
    ajout(nb, s, s1);
  std::cout << std::endl;
  return 0;
}
void ajout(int nbC, std::string t1, std::string t2)
{
  if (nbC > 0)
  {
    std::cout << "(";
    ajout(nbC - 1, t1, t2);
    if (nbC < 2)
      std::cout << t1;
    std::cout << " + ";
    if (nbC < 2)
    {
      std::cout << t2; //std::cout << "nbC = " << nbC;
    }
    ajout(nbC - 1, t1, t2);
    std::cout << ")";
  }
}
