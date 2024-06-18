#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int h{0}, f{0};
  std::cin >> h >> f;
  if (h <= 5 && f >= 8)
  {
    std::cout << "Tinuviel" << std::endl;
  }
  if (h >= 10 && f >= 10)
  {
    std::cout << "Calaelen" << std::endl;
  }
  if (h <= 8 && f <= 5)
  {
    std::cout << "Falarion" << std::endl;
  }
  if (h >= 12 && f <= 7)
  {
    std::cout << "Dorthonion" << std::endl;
  }
  return 0;
}
