#include <iostream>
int main()
{
  int nbTotalPosition{0}, changementDePosition{0};
  std::cin >> nbTotalPosition >> changementDePosition;
  int position [1000] = {0};
  for (int i{0}; i < nbTotalPosition; i++)
  {
    std::cin >> position [i];
  }
  
  for (int i{0}; i < changementDePosition; i++)
  {
    int pos1{0}, pos2{0};
    std::cin >> pos1 >> pos2;
    int tmp{position[pos1]};
    position [pos1] = position [pos2];
    position [pos2] = tmp;
  }
  for (int i{0}; i < nbTotalPosition; i++)
  {
    std::cout << position [i] << std::endl;
  }
  return 0;
}
