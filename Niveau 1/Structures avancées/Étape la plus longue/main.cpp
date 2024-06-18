#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int nbJour{0}, dMax{0};
   std::cin >> nbJour;
   for(int i{1}; i <= nbJour; i++)
   {
      int dj{0};
      std::cin >> dj;
      if(dj > dMax)
      {
         dMax = dj;
      }
   }
   std::cout << dMax << std::endl;
  
  return 0;
}
