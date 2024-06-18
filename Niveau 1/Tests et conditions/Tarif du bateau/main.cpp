#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int age{0};
  std::cin>> age;
  
  if(age<21)
  {
     std::cout<<"Tarif réduit"<<std::endl;
  }
  else
  {
     std::cout<<"Tarif plein"<<std::endl;
  }
  return 0;
}
