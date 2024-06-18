#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int dateDebut{0}, dateFin{0}, nbInvites{0}, nb{0};
  std::cin >> dateDebut >> dateFin >> nbInvites;
  for (int i{1}; i <= nbInvites; ++i)
  {
    int dateArrivee{0}, dateDepart{0};
    std::cin >> dateArrivee >> dateDepart;
    if ((dateDepart < dateDebut && dateArrivee < dateDebut) || (dateArrivee > dateFin && dateDepart > dateFin))
    {
      nb++;
    }
  }
  nb = nbInvites - nb;
  std::cout << nb << std::endl;
  return 0;
}
