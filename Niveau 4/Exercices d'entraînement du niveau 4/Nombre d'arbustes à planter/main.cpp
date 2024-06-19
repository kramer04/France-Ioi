#include <iostream>
#include <array>
using Lab = std::array<std::array<char, 1001>, 1001>;
Lab lab;
int main()
{
  std::ios::sync_with_stdio(false);
  int L {0}, C {0};
  std::cin >> L >> C;
  int route {0};
  for (int i {0}; i < L; i++)
  {
    for (int j {0}; j < C; j++)
    {
      std::cin >> lab [i][j];
      if (lab [i][j] == '.')
        route++;
    }
  }
  std::cout << L * C - route << '\n';
  return 0;
}
