// code 1
#include <iostream>
#include <vector>
#include <utility>
class UnionFind
{
  public:
  UnionFind(int size) : parent(size), rank(size, 0)
  {
    for (int i = 0; i < size; ++i)
    {
      parent [i] = i;
    }
  }
  int find(int p)
  {
    if (parent [p] != p)
    {
      parent [p] = find(parent [p]); // path compression
    }
    return parent [p];
  }
  bool union_sets(int p, int q)
  {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ)
    {
      return false;
    }
    if (rank [rootP] > rank [rootQ])
    {
      parent [rootQ] = rootP;
    }
    else if (rank [rootP] < rank [rootQ])
    {
      parent [rootP] = rootQ;
    }
    else
    {
      parent [rootQ] = rootP;
      rank [rootP]++;
    }
    return true;
  }
  private:
  std::vector<int> parent;
  std::vector<int> rank;
};
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int N, R;
  std::cin >> N >> R;
  UnionFind uf(N);
  std::vector<std::pair<int, int>> meetings(R);
  for (int i = 0; i < R; ++i)
  {
    std::cin >> meetings [i].first >> meetings [i].second;
  }
  for (const auto &meeting : meetings)
  {
    int worker1 = meeting.first;
    int worker2 = meeting.second;
    if (uf.union_sets(worker1, worker2))
    {
      std::cout << worker1 << " " << worker2 << '\n';
    }
  }
  return 0;
}
