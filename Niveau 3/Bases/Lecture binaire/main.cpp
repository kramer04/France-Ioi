#include <iostream>
#include <string>
#include <cmath>
int base10(std::string nb);
int main()
{
  std::string n{};
  std::cin >> n;
  std::cout << base10(n) << std::endl;
  return 0;
}
int base10(std::string nb)
{
  int t{(int)nb.size()}, i{0};
  int dix{0};
  int o{0};
  while (i != t)
  {
    o = (int)nb [i]-48;
    dix += o * (int)pow(2, t - i - 1);
    i++;
  }
  std::cout << std::endl;
  return dix;
}
