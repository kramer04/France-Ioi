#include <iostream>
#include <vector>
#include <algorithm>
int max_point(std::vector<int> &a, int ls, int n);
int main()
{
  std::ios_base::sync_with_stdio(0);
  int ls {0}, n {0};
  std::cin >> ls >> n;
  std::vector<int> absc(n);
  for (int i {0}; i < n; i++)
    std::cin >> absc [i];
  std::sort(absc.begin(), absc.end());
  std::cout << max_point(absc, ls, n) << '\n';
  return 0;
}
int max_point(std::vector<int> &a, int ls, int n)
{
  int max {0}, count {0};
  int k {0};
  for (int i {0}; i < n; i++)
  {
    while (k < n && (a [k] - a [i]) <= ls)
      k++;
    count = k - i;
    if (count > max)
      max = count;
  }
  return max;
}
