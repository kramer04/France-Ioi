#include <iostream>
#include <map>
int max_f(int count, int max)
{
  return (count > max) ? count : max;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nb;
  std::cin >> nb;
  std::map<int, int> carton;
  int n, max {0};
  for (int i {0}; i < nb; i++)
  {
    std::cin >> n;
    carton [n] = carton [n] + 1;//carton[n] est la valeur
  }
  for (auto it = carton.begin(); it != carton.end(); it++)
    max = max_f(it->second, max);
  std::cout << max << '\n';
  return 0;
}
