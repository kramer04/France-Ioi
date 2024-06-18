#include <iostream>
#include <deque>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbRequetes{0}, nbC{0}, k{0};
  std::cin >> nbRequetes;
  std::deque<int> affiche;
  for (int i{0}; i < nbRequetes; i++)
  {
    char c;
    std::cin >> c;
    if (c == 'Q')
      std::cout << nbC << std::endl;
    if (c == 'C')
    {
      affiche.push_back(0);
      std::cin >> affiche [nbC];
      if (nbC > 0 && affiche [nbC] >= affiche [0])
      {
        affiche.erase(affiche.begin(), affiche.begin() + nbC); //std::cout << " affiche[0] = " << affiche [0] << std::endl;
        nbC = 1;
      }
      else if (nbC > 0 && affiche [nbC] >= affiche [nbC - 1])
      {
        k = nbC;
        while (k > 0 && affiche [k] >= affiche [k - 1])
        {
          affiche.erase(affiche.begin() + k - 1);
          k--;
          nbC = (int)affiche.size();
        }
      }
      else
        nbC = (int)affiche.size();
      
    }
  }
  return 0;
}
