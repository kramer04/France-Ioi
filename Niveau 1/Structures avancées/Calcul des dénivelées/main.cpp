#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
  int nbrMD{0}, dnvp{0}, dnvm{0};
  std::cin >> nbrMD;
  for (int i{1}; i <= nbrMD; i++)
  {
    int dn{0};
    std::cin >> dn;
    
    if(dn > 0)
    {
       dnvp = dnvp + dn;
    }
    else
    {
       dnvm += dn;
    } 
  }
   std::cout<<dnvp<<std::endl;
   std::cout<<abs(dnvm)<<std::endl;
  return 0;
}
