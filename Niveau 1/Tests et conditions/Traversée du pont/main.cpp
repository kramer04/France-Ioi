#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int jet1,jet2;
  std::cin>>jet1>>jet2;
  if(jet1+jet2>=10)
  {
     std::cout<<"Taxe spéciale !"<<std::endl;
     std::cout<<36<<std::endl;
  }
  else
  {
     std::cout<<"Taxe régulière"<<std::endl;
     std::cout<<(jet1+jet2)*2<<std::endl;
  }
  return 0;
}
