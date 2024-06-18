#include <iostream>
int main()
{
   int nbLieux{0}, nbV{0};
   std::cin>>nbLieux;
   
   for(int i{1}; i <= nbLieux; i++)
   {
      int nbH;
      std::cin>>nbH;
      if(nbH > 10000)
      {
         nbV++;
      }
   }
   std::cout << nbV << std::endl;
   return 0;
}
