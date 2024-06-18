#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int dateDebut1{0}, dateFin1{0}, dateDebut2{0}, dateFin2{0};
  std::cin >> dateDebut1 >> dateFin1 >> dateDebut2 >> dateFin2;
  if ((dateDebut1 <= dateDebut2 && dateFin1 >= dateDebut2 && dateFin1 <= dateFin2) || ((dateDebut1 >= dateDebut2 && dateDebut1 <= dateFin2) && dateFin1 >= dateFin2) || (dateDebut1 <= dateDebut2 && dateFin1 >= dateFin2) || ((dateDebut1 >= dateDebut2) && (dateDebut1 <= dateFin2) && (dateFin1 >= dateDebut2) && (dateFin1 <= dateFin2)))
  {
    std::cout << "Amis" << std::endl;
  }
  else
  {
    std::cout << "Pas amis" << std::endl;
  }
  return 0;
}
