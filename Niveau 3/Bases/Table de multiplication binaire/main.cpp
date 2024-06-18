#include <iostream>
#include <string>
std::string enBase2(int i, int j);
int main()
{
  std::ios::sync_with_stdio(false);
  int lc{0};
  std::cin >> lc;
  for (int i{1}; i <= lc; ++i)
  {
    for (int j{1}; j <= lc; ++j)
    {
      std::cout << enBase2(i, j) << '\t';
    }
    std::cout << '\n';
  }
  return 0;
}
std::string enBase2(int i, int j)
{
  std::string base2{};
  int nb{i * j}, resultat{0};
  while (nb > 0)
  {
    resultat = nb % 2;
    base2 = std::to_string(resultat) + base2;
    nb /= 2;
  }
  return base2;
}
