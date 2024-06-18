#include <iostream>
#include <vector>
#include <algorithm>
struct Intervalle
{
  int d, f;
};
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbI {0};
  std::cin >> nbI;
  std::vector<Intervalle>plage(nbI);
  int plageMax {0};
  for (int i {0}; i < nbI; ++i)
  {
    std::cin >> plage [i].d >> plage [i].f;
    if (plage [i].f > plageMax)
      plageMax = plage [i].f;
  }
  auto tri = [](Intervalle &lhs, Intervalle &rhs) {return lhs.d < rhs.d; };
  std::sort(plage.begin(), plage.end(), tri);
  auto itd = plage.begin() + 1;
  int max {plageMax - (itd - 1)->d};
  for (; itd != plage.end(); itd++)
  {
    if (itd->d < (itd - 1)->f && itd->f < (itd - 1)->f)
    {
      plage.erase(itd);
      itd--;
    }
    else if (itd->d > (itd - 1)->f)
    {
      max -= itd->d - (itd - 1)->f;
    }
  }
  std::cout << max << '\n';
  return 0;
}
