#include <iostream>
#include <vector>
int main()
{
  std::ios::sync_with_stdio(false);
  int n {0}, r {0};
  std::cin >> n >> r;
  std::vector<int>v(n + 1);
  v [0] = 0;
  for (int i {1}; i <= n; i++)
  {
    std::cin >> v [i];
    v [i] += v [i - 1];
  }
  for (int i {1}; i <= r; i++)
  {
    int a {0}, b {0};
    std::cin >> a >> b;
    std::cout << v [b] - v [a - 1] << '\n';
  }
  std::cout << '\n';
  return 0;
}
