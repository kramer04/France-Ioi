#include <iostream>
#include <vector>
#include <algorithm>
struct UnionFind
{
  std::vector<int> parent;
  std::vector<int> size;
  int max_component_size;
  UnionFind(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      parent [i] = i;
    max_component_size = 1;
  }
  int find(int v)
  {
    if (parent [v] == v)
      return v;
    return parent [v] = find(parent [v]);
  }
  void union_sets(int a, int b)
  {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b)
    {
      if (size [root_a] < size [root_b])
        std::swap(root_a, root_b);
      parent [root_b] = root_a;
      size [root_a] += size [root_b];
      max_component_size = std::max(max_component_size, size [root_a]);
    }
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A;
  std::cin >> N >> A;
  UnionFind uf(N);
  for (int i = 0; i < A; ++i)
  {
    int u, v, length;
    std::cin >> u >> v >> length;
    uf.union_sets(u, v);
    std::cout << uf.max_component_size << "\n";
  }
  return 0;
}
