#include <iostream>
#include "robot.h"
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int i{1};
   repeat(10)
   {
      repeat(i)
      {
         droite();
      }
      ramasser();
      repeat(i)
      {
         gauche();
      }
      deposer();
      i++;
   }
   
}
