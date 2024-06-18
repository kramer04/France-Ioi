#include <iostream>
#include <string>
#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string ligne{""};
  getline(std::cin, ligne);
  for (int i{0}; i < (int)ligne.size(); i++)
  {
    std::cout << (char)toupper(ligne [i]);
  }
  std::cout << std::endl;
  return 0;
}
