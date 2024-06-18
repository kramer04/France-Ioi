#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int coteBase{17};
  int totalCube{0};
  for (int i{coteBase}; i >= 1; i -= 2)
  {
    totalCube = totalCube + i * i * i;
  }
  std::cout << totalCube << std::endl;
  return 0;
}
