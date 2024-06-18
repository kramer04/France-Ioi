#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int xMin{0}, yMin{0}, xMax{0}, yMax{0},nbTotalMaison{0}, nbTMR{0};
  std::cin >> xMin >> xMax >> yMin >> yMax >> nbTotalMaison;
  for (int i{1}; i <= nbTotalMaison; i++)
  {
    int x{0}, y{0};
    std::cin >> x >> y;
    if (x >= xMin && x <= xMax && y >= yMin && y <= yMax)
    {
      nbTMR++;
    }
  }
  std::cout << nbTMR << std::endl;
  return 0;
}
