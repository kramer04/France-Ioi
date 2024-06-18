#include <iostream>
std::string show_binary(int nb);
int main()
{
  int n{0};
  std::cin >> n;
  
  std::cout << show_binary(n) << std::endl;
  return 0;
}
std::string show_binary(int nb)
{
  std::string bin{};
  if (nb == 0)
    return bin = "0";
  while (nb > 0)
  {
    if (nb % 2 == 0) bin.insert(bin.begin(), '0');
    else bin.insert(bin.begin(), '1');
    nb >>= 1;
  }
  return bin;
}
