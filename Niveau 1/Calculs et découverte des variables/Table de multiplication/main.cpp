#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  for (int i{1}; i <= 20; i++)
  {
    for (int j{1}; j <= 20; j++)
    {
      std::cout << i * j << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
