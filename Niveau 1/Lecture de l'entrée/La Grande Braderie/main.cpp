#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int positionDepart{0}, largeurEmplacement{0}, nbVendeurs{0};
   std::cin>>positionDepart;
   std::cin>>largeurEmplacement;
   std::cin>>nbVendeurs;
   
   repeat(nbVendeurs + 1)
   {
      std::cout<<positionDepart<<std::endl;
      positionDepart += largeurEmplacement;
   }
   
}
