#include <iostream>
#include <vector>
struct SegmentTree
{
  std::vector<int> tree, lazy;
  int n;
  SegmentTree(int size)
  {
    n = size;
    tree.assign(2 * n, 0);
    lazy.assign(2 * n, 0);
  }
  void apply(int pos, int value, int length)
  {
    tree [pos] += value * length;
    if (pos < n)
    {
      lazy [pos] += value;
    }
  }
  void push(int pos, int start, int end)
  {
    if (lazy [pos] != 0)
    {
      int mid = (start + end) / 2;
      apply(pos * 2, lazy [pos], mid - start + 1);
      apply(pos * 2 + 1, lazy [pos], end - mid);
      lazy [pos] = 0;
    }
  }
  void update(int l, int r, int value, int pos = 1, int start = 0, int end = -1)
  {
    if (end == -1) end = n - 1;
    push(pos, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r)
    {
      apply(pos, value, end - start + 1);
      return;
    }
    int mid = (start + end) / 2;
    update(l, r, value, pos * 2, start, mid);
    update(l, r, value, pos * 2 + 1, mid + 1, end);
    tree [pos] = tree [pos * 2] + tree [pos * 2 + 1];
  }
  int query(int index, int pos = 1, int start = 0, int end = -1)
  {
    if (end == -1) end = n - 1;
    push(pos, start, end);
    if (index < start || index > end) return 0;
    if (start == end) return tree [pos];
    int mid = (start + end) / 2;
    if (index <= mid)
    {
      return query(index, pos * 2, start, mid);
    }
    else
    {
      return query(index, pos * 2 + 1, mid + 1, end);
    }
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
    if (type == 'D')
    {
      int L, U, D;
      std::cin >> L >> U >> D;
      st.update(L, U, D);
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
