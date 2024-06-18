#include <iostream>
#include <set>
#include <list>
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbCibles {0}, nbLots {0};
  std::cin >> nbCibles;
  std::list<int>tirs(nbCibles, 0);
  for (auto it = tirs.begin(); it != tirs.end(); ++it)
    std::cin >> *it;
  std::cin >> nbLots;
  std::set<int>lots;
  int l {0};
  for (int i {0}; i < nbLots; ++i)
  {
    std::cin >> l;
    lots.insert(l);
  }
  std::set<int>::iterator gain, tmp {lots.begin()};
  
  for (auto liste = tirs.begin(); liste != tirs.end(); liste++)
  {
    gain = tmp;
    do
    {
      gain++;
      if (*gain > *liste || gain == lots.end())
      {
        gain--;
        tmp = gain;
        std::cout << *gain << " ";
        //gain = lots.end();
        break;
      }
    } while (gain != lots.end());
  }
  std::cout << '\n';
  return 0;
}
