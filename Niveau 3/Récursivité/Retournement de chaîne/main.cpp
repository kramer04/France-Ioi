#include <iostream>
#include <string>
void reverse(size_t t, std::string &s);
int main()
{
  std::string s{};
  getline(std::cin, s);
  size_t t{s.size()};
  reverse(t - 1, s);
  std::cout << std::endl;
  return 0;
}
void reverse(size_t t, std::string &s)
{
  std::cout << s [t];
  if (t > 0)
  {
    reverse(t - 1, s);
  }
}
