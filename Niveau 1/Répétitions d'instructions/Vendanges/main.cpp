#include "robot.h"
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   repeat(20)
   {
    ramasser();
   
   repeat(15)
   {
    droite();
   }
   deposer();
   repeat(15)
   {
    gauche();
   }
   }
   return 0;
}
