// code 1
// algorithme de Arbre de segment
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
struct SegmentTree
{
  std::vector<int> tree;
  int n;
  SegmentTree(const std::vector<int> &arr)
  {
    n = arr.size();
    tree.resize(2 * n);
    build(arr);
  }
  void build(const std::vector<int> &arr)
  {
    for (int i = 0; i < n; ++i)
    {
      tree [n + i] = arr [i];
    }
    for (int i = n - 1; i > 0; --i)
    {
      tree [i] = std::max(tree [i * 2], tree [i * 2 + 1]);
    }
  }
/*
  void update(int pos, int value)
  {
    pos += n;
    tree [pos] = value;
    while (pos > 1)
    {
      pos /= 2;
      tree [pos] = std::max(tree [2 * pos], tree [2 * pos + 1]);
    }
  }
*/
  int query(int l, int r)
  {
    l += n;
    r += n;
    int max_val = std::numeric_limits<int>::min();
    while (l <= r)
    {
      if (l % 2 == 1)
      {
        max_val = std::max(max_val, tree [l]);
        l++;
      }
      if (r % 2 == 0)
      {
        max_val = std::max(max_val, tree [r]);
        r--;
      }
      l /= 2;
      r /= 2;
    }
    return max_val;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  int nbElement;
  std::cin >> nbElement;
  nbElement = 1 << nbElement;
  std::vector<int> arr(nbElement);
  for (int i {0}; i < nbElement; i++)
    std::cin >> arr [i];
  int nbIntervalle;
  std::cin >> nbIntervalle;
  int k, l;
  SegmentTree sparse(arr);
  for (int i {0}; i < nbIntervalle; i++)
  {
    std::cin >> k >> l;
    // si l'intervalle est donné de 1 à nbElement : k = k - 1, l = l - 1
    std::cout << sparse.query(k, l) << '\n';
  }
  return 0;
}
