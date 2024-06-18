#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int posKm{0}, nbV{0}, n{0};
  std::cin >> posKm >> nbV;
  for (int i{1}; i <= nbV; i++)
  {
    int km{0};
    std::cin >> km;
    if (abs(posKm - km) <= 50)
    {
      n++;
    }
  }
  std::cout << n << std::endl;
  return 0;
}
