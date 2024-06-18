#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  int n {0};
  std::cin >> n;
  std::vector<int>v(n);
  for (int i {0}; i < n; i++)
    std::cin >> v [i];
  std::vector<int>max(n);
  max [0] = v [0];
  int res {max [0]};
  for (int i {1}; i < n; i++)
  {
    max [i] = std::max(v [i], max [i - 1] + v [i]);
    res = std::max(res, max [i]);
  }
  std::cout << std::max(res, 0);
  return 0;
}
