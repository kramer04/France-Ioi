#include <iostream>
#include <vector>
#include <algorithm>
struct Pair
{
  int d, f;
  Pair(int d, int f):d(d), f(f) {};
  /* bool operator<(Pair const &lhs) const
  {
    if (f != lhs.f && d <= lhs.d)
      return f < lhs.f;
    return (d < lhs.d);
  } */
  bool operator<(Pair const &lhs) const
  {
    if (d != lhs.d)
      return d < lhs.d;
    return (f > lhs.f);
  }
};
int fermeture(std::vector<Pair> &r, int unite);
int main()
{
  std::ios_base::sync_with_stdio(0);
  int unite {0}, nbf {0};
  std::cin >> unite >> nbf;
  std::vector<Pair> rep;
  for (int i {0}; i < nbf; ++i)
  {
    int d {0}, f {0};
    std::cin >> d >> f;
    if (f < d)
    {
      rep.push_back({d, unite});
      rep.push_back({0, f});
    }
    else
      rep.push_back({d, f});
  }
  sort(rep.begin(), rep.end());
  std::cout << fermeture(rep, unite) << '\n';
  return 0;
}
int fermeture(std::vector<Pair> &r, int unite)
{
  int max {r [0].d}, tmp {r [0].f};
  for (size_t i {1}; i < r.size(); ++i)
  {
    if (r [i].d <= tmp && r [i].f >= tmp)
      tmp = r [i].f;
    else if (r [i].d > tmp)
    {
      if (max < (r [i].d - tmp))
        max = r [i].d - tmp;
      tmp = r [i].f;
    }
  }
  if (max < (unite + r [0].d - tmp))
    max = unite + r [0].d - tmp;
  return max;
}
