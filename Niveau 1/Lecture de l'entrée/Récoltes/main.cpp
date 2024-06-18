#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main()
{
   int cote{0}, production{23};
   std::cin>>cote;
   std::cout << cote * cote * production << std::endl;
   
}
