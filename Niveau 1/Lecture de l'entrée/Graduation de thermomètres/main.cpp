#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int tempMax{0}, tempMin{0};
   std::cin >> tempMin >> tempMax;
   int ecart = tempMax - tempMin + 1;
   
   repeat(ecart)
   {
      std::cout<< tempMin << std::endl;
      tempMin++;
   }
   
}
