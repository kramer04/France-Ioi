#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int a, e;
  std::cin>>a>>e;
  if(a>e+10)
  {
     std::cout<<"La famille Arignon a un champ trop grand"<<std::endl;
  }
  if(e>a+10)
  {
     std::cout<<"La famille Evaran a un champ trop grand"<<std::endl;
  }
  return 0;
}
