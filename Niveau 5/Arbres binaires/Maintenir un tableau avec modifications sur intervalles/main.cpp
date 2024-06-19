#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
struct SegmentTree
{
  std::vector<int> tree, lazy;
  int n;
  SegmentTree(int size)
  {
    n = size;
    tree.assign(2 * n, 0);
    lazy.assign(2 * n, -1);
  }
  void apply(int pos, int value)
  {
    tree [pos] = value;
    if (pos < n)
    {
      lazy [pos] = value;
    }
  }
  void push(int pos)
  {
    for (int h = __builtin_clz(1) - __builtin_clz(n); h > 0; --h)
    {
      int i = pos >> h;
      if (lazy [i] != -1)
      {
        apply(i * 2, lazy [i]);
        apply(i * 2 + 1, lazy [i]);
        lazy [i] = -1;
      }
    }
  }
  void update(int l, int r, int value, int pos = 1, int start = 0, int end = -1)
  {
    if (end == -1) end = n - 1;
    push(pos);
    if (r < start || end < l) return;
    if (l <= start && end <= r)
    {
      apply(pos, value);
      return;
    }
    int mid = (start + end) / 2;
    update(l, r, value, pos * 2, start, mid);
    update(l, r, value, pos * 2 + 1, mid + 1, end);
    tree [pos] = std::max(tree [pos * 2], tree [pos * 2 + 1]);
  }
  int query(int index, int pos = 1, int start = 0, int end = -1)
  {
    if (end == -1) end = n - 1;
    push(pos);
    if (index < start || index > end) return -1;
    if (start == end) return tree [pos];
    int mid = (start + end) / 2;
    int left_query = query(index, pos * 2, start, mid);
    int right_query = query(index, pos * 2 + 1, mid + 1, end);
    return std::max(left_query, right_query);
  }
};
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int H, R;
  std::cin >> H >> R;
  int size = 1 << H;
  SegmentTree st(size);
  for (int i = 0; i < R; ++i)
  {
    char type;
    std::cin >> type;
    if (type == 'M')
    {
      int L, U, V;
      std::cin >> L >> U >> V;
      st.update(L, U, V);
    }
    else if (type == 'V')
    {
      int K;
      std::cin >> K;
      std::cout << st.query(K) << "\n";
    }
  }
  return 0;
}
