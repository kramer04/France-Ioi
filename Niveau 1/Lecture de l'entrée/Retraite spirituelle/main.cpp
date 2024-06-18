#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int temps{16}, jour{0};
   std::cin>> jour;
   std::cout<< jour * temps * 3600 << std::endl;
}
