//faire un programme encpre plus optimisé
#include <iostream>
#include <vector>
std::vector<int> C;
int find(std::vector <int> &C, int x) { return (C [x] == x) ? x : C [x] = find(C, C [x]); }
int find(int x) { return (C [x] == x) ? x : C [x] = find(C [x]); }
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  int n, m, a, b;
  std::cin >> n >> m;
  for (int i = 0; i <= n; ++i)
  {
    C.push_back(i);
  }
  for (int i = 0; i < m; ++i)
  {
    std::cin >> a >> b;
    int ka = find(a);
    int kb = find(b);
    if (ka != kb)
    {
      std::cout << a << " " << b << "\n";
      C [kb] = ka;
    }
  }
  return 0;
}
