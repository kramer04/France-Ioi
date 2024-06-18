#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int mdp{0};
  std::cin>>mdp;
  if(mdp==64741)
  {
     std::cout<<"Bon festin !"<<std::endl;
  }
  else
  {
     std::cout<<"Allez-vous en !"<<std::endl;
  }
  return 0;
}
