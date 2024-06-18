#include <iostream>
#include <string>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string auteur{""};
  int age{0};
  std::cin >> auteur >> age;
  int c = (int)auteur [0] - 64;
  char d;
  (age % 26 == 0) ? d = 90 : d = age % 26 + 64;
  std::cout << c << d << std::endl;
  return 0;
}
