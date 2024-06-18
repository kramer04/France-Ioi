#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int ha{0}, prix{0};
  std::cin>>ha;
  prix = ha * 5 + 10;
  if(prix>53)
  {
     prix = 53;
  }
  std::cout<<prix<<std::endl;
  return 0;
}
