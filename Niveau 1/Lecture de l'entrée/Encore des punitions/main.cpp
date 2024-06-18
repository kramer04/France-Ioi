#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int entree{0};
   std::cin >> entree;
   repeat(entree)
   {
      std::cout<< "Je dois suivre en cours" << std::endl;
   }
  
  return 0;
}
