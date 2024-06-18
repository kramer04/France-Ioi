#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main(){
   int i{100};
   repeat(101)
   {
      std::cout<<i<<std::endl;
      i--;
   }
   std::cout<<"Décollage !"<<std::endl;
}
