#include <iostream>
#include <vector>
#include <algorithm>
using Case = std::vector<int>;
void cherche(std::vector<int> &c, Case &v, int case1);
int main()
{
  std::ios::sync_with_stdio(false);
  int n {0};
  std::cin >> n;
  Case objet;
  for (int i {0}; i < n; i++)
  {
    int tmp {0};
    std::cin >> tmp;
    objet.push_back(tmp);
  }
  int nbc {0}, code1 {0}, code2 {0};
  std::cin >> nbc;
  for (int i {0}; i < nbc; i++)
  {
    Case c1;
    Case c2;
    std::cin >> code1 >> code2;
    cherche(objet, c1, code1);
    cherche(objet, c2, code2);
    for (size_t i {0}; i < c1.size(); i++)
    {
      auto f = std::find(begin(c2), end(c2), c1 [i]);
      if (f != end(c2))
      {
        std::cout << *f << "\n";
        i = c1.size();
      }
    }
  }
  return 0;
}
void cherche(std::vector<int> &c, Case &v, int case1)
{
  v.push_back(case1);
  if (case1 != 0)
  {
    cherche(c, v, c [case1 - 1]);
  }
}
