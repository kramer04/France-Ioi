#include <iostream>
#include <string>
int main()
{
   for(char c = 'b'; c <= 'z'; c++)
   {
      if(c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y')
      {
         std::cout << c << " ";
      }
   }
   std::cout << std::endl;
   return 0;
}
