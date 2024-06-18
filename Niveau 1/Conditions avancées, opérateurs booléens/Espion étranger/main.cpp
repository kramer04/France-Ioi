#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int dateDebut{0}, dateFin{0}, nbEntrees{0}, nbDate{0};
  std::cin >> dateDebut >> dateFin >> nbEntrees;
  for (int i{1}; i <= nbEntrees; i++)
  {
    int date{0};
    std::cin >> date;
    if (date >= dateDebut && date <= dateFin)
    {
      nbDate++;
    }
  }
  std::cout << nbDate << std::endl;
  return 0;
}
