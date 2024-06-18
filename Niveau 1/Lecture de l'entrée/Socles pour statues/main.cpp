#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int l1{0}, ld{0};
   std::cin >> l1;
   std::cin >> ld;
   int nbSocle{l1 - ld + 1};
   int volume{0};
   repeat(nbSocle)
   {
      volume += l1 * l1;
      l1--;
   }
   std::cout<<volume<<std::endl;
}
