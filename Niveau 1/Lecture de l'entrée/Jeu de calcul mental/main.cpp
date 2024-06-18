#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int nbNombres {0};
   std::cin>>nbNombres;
   int nbdebut{66}, i{1};
   
   repeat(nbNombres)
   {
      nbdebut = nbdebut * i;
      std::cout<< nbdebut << std::endl;
      i++;
   }
   
   
}
