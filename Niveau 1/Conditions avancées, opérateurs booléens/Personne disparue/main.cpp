#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int num{0}, tailleListe{0};
  bool test = false;
  std::cin >> num >> tailleListe;
  for (int i{1}; i <= tailleListe; ++i)
  {
    int dansListe{0};
    std::cin >> dansListe;
    if (num == dansListe)
    {
      test = true;
    }
  }
  if (test == true)
  {
    std::cout << "Sorti de la ville" << std::endl;
  }
  else
  {
    std::cout << "Encore dans la ville" << std::endl;
  }
  return 0;
}
