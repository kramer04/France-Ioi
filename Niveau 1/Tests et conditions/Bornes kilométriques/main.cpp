#include <iostream>
int main()
{
   int num1{0}, num2{0}, resultat{0};
   std::cin>>num1>>num2;
   resultat = num1 - num2;
   if(resultat < 0)
      {
         resultat = -1 * resultat;
      }
      
   std::cout<<resultat<<std::endl;
}
