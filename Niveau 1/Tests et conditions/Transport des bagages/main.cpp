#include <iostream>
int main()
{
   int paquet{0}, poids{0};
   std::cin>>paquet>>poids;
   
   if(paquet*poids>105)
   {
      std::cout<<"Surcharge !"<<std::endl;
   }
}
