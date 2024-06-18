#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
  std::ios::sync_with_stdio(false);
  int N_bacs{0}, M_camion{0};
  std::cin >> N_bacs >> M_camion;
  std::vector<int> pollution{0};
  for (int i{0}; i < N_bacs; i++)
  {
    pollution.push_back(0);
    std::cin >> pollution [i];
  }
  std::sort(std::begin(pollution), std::end(pollution), [](const int p, const int p1) {return p > p1; });
  for (int i{0}; i < M_camion; i++)
  {
    std::cout << pollution [i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
