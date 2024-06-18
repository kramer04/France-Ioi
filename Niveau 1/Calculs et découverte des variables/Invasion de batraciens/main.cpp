#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int i{1337};
   repeat(12)
   {
    i = i * 2; 
   }
   std::cout << i << std::endl;
}
