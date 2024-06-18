#include <iostream>
#include <vector>
#include <list>
std::vector<std::list<int>> objet(20001);
int cherche(int ito, int count, int max);
int main()
{
  std::ios::sync_with_stdio(false);
  int nb{0};
  std::cin >> nb;
  
  for (int i{0}; i < nb; i++)
  {
    int c{0};
    std::cin >> c;
    objet [c].insert(objet [c].begin(), i);
  }
  std::cout << cherche(0, 1, 0) << std::endl;
  return 0;
}
int cherche(int ito, int count, int max)
{
  for (auto i = objet [ito].begin(); i != objet [ito].end(); i++)
  {
    if (count > max)
      max = count;
    max = cherche(*i + 1, count + 1, max);
    //if (count > max)
    //  max = count;
  }
  return max;
}
