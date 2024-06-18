#include <iostream>
int main()
{
  int nbTotalDeplacement {0};
  int deplacement [1000] = {0};
  std::cin >> nbTotalDeplacement;
  for (int i{0}; i < nbTotalDeplacement; i++)
  {
    std::cin >> deplacement [i];
    if (deplacement [i] == 1)
    {
      deplacement [i] = 2;
    }
    else if (deplacement[i] == 2)
    {
      deplacement [i] = 1;
    }
    if (deplacement [i] == 4)
    {
      deplacement [i] = 5;
    }
    else if (deplacement [i] == 5)
    {
      deplacement [i] = 4;
    }
  }
  for (int i{nbTotalDeplacement - 1}; i >= 0; i--)
  {
    std::cout << deplacement [i] << std::endl;
  }
  return 0;
}
