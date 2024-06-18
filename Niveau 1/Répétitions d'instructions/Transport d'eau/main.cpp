#include <iostream>
#include "robot.h"
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
using namespace std;
int main()
{
   gauche();
   gauche();
   std::cout<<"Bonjour, laissez-moi vous aider"<<std::endl;
   ramasser();
      repeat (32)
      {
         droite();
      }
   deposer();
}
