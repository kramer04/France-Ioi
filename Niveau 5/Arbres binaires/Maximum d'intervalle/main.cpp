//code 7
// algorithme de sparse
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
struct SparseTable
{
  std::vector<std::vector<int>> st;
  std::vector<int> log;
  SparseTable(const std::vector<int> &arr)
  {
    int n = arr.size();
    int k = std::log2(n) + 1;
    st.assign(n, std::vector<int>(k));
    log.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
      log [i] = log [i / 2] + 1;
    }
    for (int i = 0; i < n; ++i)
    {
      st [i][0] = arr [i];
    }
    for (int j = 1; (1 << j) <= n; ++j)
    {
      for (int i = 0; (i + (1 << j) - 1) < n; ++i)
      {
        st [i][j] = std::max(st [i][j - 1], st [i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) const
  {
    int j = log [r - l + 1];
    return std::max(st [l][j], st [r - (1 << j) + 1][j]);
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  int nbElement;
  std::cin >> nbElement;
  std::vector<int> arr(nbElement);
  for (int i {0}; i < nbElement; i++)
    std::cin >> arr [i];
  int nbIntervalle;
  std::cin >> nbIntervalle; //std::cout << '\n';
  int k, l;
  SparseTable sparse(arr);
  for (int i {0}; i < nbIntervalle; i++)
  {
    std::cin >> k >> l;
    std::cout << sparse.query(k - 1, l - 1) << '\n';
  }
  return 0;
}
