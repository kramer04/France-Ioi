#include <iostream>
#include <string>
int main()
{
  std::string texte{""};
  std::cin >> texte;
  if (texte [0] >= 'A' && texte [0] <= 'F')
  {
    std::cout << 1 << std::endl;
  }
  else if (texte [0] >= 'G' && texte [0] <= 'P')
  {
    std::cout << 2 << std::endl;
  }
  else
  {
    std::cout << 3 << std::endl;
  }
  return 0;
}
