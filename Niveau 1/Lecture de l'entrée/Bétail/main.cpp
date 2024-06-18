#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbKarvas{0}, total{0};
  repeat(20)
  {
     std::cin >> nbKarvas;
     total += nbKarvas;
  }
  std::cout<<total<<std::endl;
}
