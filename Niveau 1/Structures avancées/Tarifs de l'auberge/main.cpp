#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int bagage{0}, age{0};
  std::cin >> age >> bagage;
  if (age == 60)
  {
    std::cout << 0 << std::endl;
  }
  if (age < 10)
  {
    std::cout << 5 << std::endl;
  }
  if (age >= 10 && age != 60)
  {
    if (bagage >= 20)
    {
      std::cout << 40 << std::endl;
    }
    else
    {
      std::cout << 30 << std::endl;
    }
  }
  return 0;
}
