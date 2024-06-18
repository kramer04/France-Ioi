#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int r1x1{0}, r1x2{0}, r1y1{0}, r1y2{0}, r2x1{0}, r2x2{0}, r2y1{0}, r2y2{0}, nbPaire{0};
  std::cin >> nbPaire;
  for (int i{1}; i <= nbPaire; i++)
  {
    std::cin >> r1x1 >> r1x2 >> r1y1 >> r1y2 >> r2x1 >> r2x2 >> r2y1 >> r2y2;
    if (((r1x1 < r2x1 && r1x2 <= r2x1) || (r1x1 >= r2x2 && r1x2 > r2x2)) || (r1y1 < r2y1 && r1y2 <= r2y1) || (r1y1 >= r2y2 && r1y2 > r2y2))
    {
      std::cout << "NON" << std::endl;
    }
    else
    {
      std::cout << "OUI" << std::endl;
    }
  }
  return 0;
}
