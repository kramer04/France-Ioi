#include <iostream>
#include <vector>
#include <algorithm>
struct Pair
{
  int duree, freq;
  bool operator < (const Pair &autre) const
  {
    if (duree != autre.duree)
      return (duree < autre.duree);
    return (freq < autre.freq);
  }
};
double round(double var)
{
  // 37.66666 * 100 =3766.66
  // 3766.66 + .5 =3767.16    for rounding off value
  // then type cast to int so value is 3767
  // then divided by 100 so the value converted into 37.67
  double value = (int) (var * 100 + .5);
  return (double) value / 100;
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbs {0};
  std::cin >> nbs;
  std::vector<Pair> tab(nbs);
  for (int i {0}; i < nbs; ++i)
  {
    int d, f;
    std::cin >> d >> f;
    tab [i].duree = d;
    tab [i].freq = f;
  }
  //auto tri = [](Pair &lhs, Pair &rhs) {return lhs.duree < rhs.duree; };
  std::sort(tab.begin(), tab.end()); //, tri);
  double moyenne {0.0}, fMax {0.0};
  int dMax {0}, frequence_totale {0};
  for (int i {0}; i < nbs; i++)
  {
    frequence_totale += tab [i].freq;
    moyenne = (double) frequence_totale / (i + 1);
    moyenne = round(moyenne);
    if (moyenne >= fMax)
    {
      dMax = tab [i].duree;
      fMax = moyenne;
    }
  }
  if (dMax == 0)
  {
    std::cout << 0 << '\n';
  }
  else
    std::cout << dMax << '\n';
  return 0;
}
