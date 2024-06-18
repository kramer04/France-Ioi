#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main(){
repeat(20)
{
   repeat(20)
   {
      std::cout<<"OX";
   }
   std::cout<<std::endl;
   repeat(20)
   {
    std::cout<<"XO";
   }
   std::cout<<std::endl;
}
return 0;
}
