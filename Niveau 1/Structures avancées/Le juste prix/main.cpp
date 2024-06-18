#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbMarchands{0}, minPrix{1000000}, pos{0}, maxPos{0};
  std::cin >> nbMarchands;
  for (int i{1}; i <= nbMarchands; i++)
  {
    int prix{0};
    std::cin >> prix;
    pos++;
    if (prix <= minPrix)
    {
      minPrix = prix;
      maxPos = pos;
    }
  }
  std::cout << maxPos << std::endl;
  return 0;
}
