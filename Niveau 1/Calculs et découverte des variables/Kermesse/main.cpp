#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int precedent{0}, gain{0};
  for (int i{1}; i < 51; i++)
  {
    gain = i + precedent;
    std::cout << gain << std::endl;
    precedent = gain;
  }
   return 0;
}
