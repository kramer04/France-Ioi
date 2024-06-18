#include <iostream>
#include <algorithm>
#include <vector>
using Vecteur = std::vector<int>;
int nombre(Vecteur &tab, int Q, int m);
int main()
{
  std::ios::sync_with_stdio(false);
  int nBloc{0};
  std::cin >> nBloc;
  Vecteur t;
  for (int i{0}; i < nBloc; i++)
  {
    t.push_back(0);
    std::cin >> t [i];
  }
  std::sort(t.begin(), t.end());
  std::cout << "\n";
  int m{(int)t.size() / 2};
  int question{0};
  std::cin >> question;
  for (int i{0}; i < question; i++)
  {
    int q{0};
    std::cin >> q;
    std::cout << nombre(t, q, m) << '\n';
  }
  return 0;
}
int nombre(Vecteur &tab, int Q, int m)
{
  Vecteur::iterator it;
  Vecteur::iterator it1;
  if (Q < tab [m])
  {
    it = tab.begin();
    it1 = tab.begin() + m - 1;
  }
  if (Q >= tab [m])
  {
    it = tab.end() - m - 1; //std::cout << "m " << m << " *it " << *it << std::endl;
    it1 = tab.end();
  }
  int nb{*it};
  int diff{0}, temp{abs(Q - *it)};
  for (; it <= it1; it++)
  {
    diff = abs(Q - *it);
    if (diff < temp)
    {
      temp = diff;
      if (nb < *it)
        nb = *it;
    }
  }
  return nb;
}
