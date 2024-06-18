#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Etape
{
  int node, etape;
};
using V = std::vector<Etape>;
//void nb_etape(std::vector<int> &node, V &etape, size_t k, int e, int nbe);
void nb_etape(std::vector<int> &node, V &etape);
bool test(Etape &lhs, Etape &rhs);
bool compare(int n, std::string &s);
std::string masque {};
int main()
{
  std::ios::sync_with_stdio(false);
  int n {0};
  std::cin >> n;
  std::vector<int> node(n);
  for (int i {0}; i < n; i++)
    std::cin >> node [i];
  std::cin >> masque;
  std::reverse(masque.begin(), masque.end());
  
  V etape;
  //nb_etape(node, etape, 0, node [0], 1);
  nb_etape(node, etape);
  std::sort(etape.begin(), etape.end(), test);
  for (size_t i {0}; i < etape.size(); i++)
    std::cout << etape [i].node << " ";
  std::cout << "\n";
  return 0;
}
void nb_etape(std::vector<int> &node, V &etape)
{
  size_t k {0};
  int e {node [0]}, nbe {1};
  while (k < node.size())
  {
    if (e == 0)
    {
      k++;
      e = k + 1;
      if (compare(k, masque))
        etape.push_back({e - 1, nbe});
      nbe = 0;
    }
    e = node [e - 1];
    nbe++;
  }
}
/* void nb_etape(std::vector<int> &node, V &etape, size_t k, int e, int nbe)
{
  if (e == 0)
  {
    k++;
    e = k + 1;
    
    if (compare(k, masque))
      etape.push_back({e - 1, nbe});
    
    nbe = 0;
  }
  if (k == node.size())
    return;
  nb_etape(node, etape, k, node [e - 1], nbe + 1);
} */
bool test(Etape &lhs, Etape &rhs)
{
  return lhs.etape < rhs.etape;
}
bool compare(int n, std::string &s)
{
  size_t i = 0;
  while (n != 0 && i < s.length())
  {
    if (s [i] == '?')
    {
      n /= 10;
      i++;
    }
    else if (s [i] - '0' != n % 10)
      return false;
    else
    {
      n /= 10;
      i++;
    }
  }
  if (n != 0 || i != s.length())
    return false;
  return true;
}
