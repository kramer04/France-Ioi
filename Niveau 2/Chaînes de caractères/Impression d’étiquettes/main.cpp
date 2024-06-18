#include <iostream>
#include <string>
int main()
{
  std::string texte{""};
  getline(std::cin, texte);
  int taille{(int)texte.size()};
  for (int i{0}; i < taille; i++)
  {
    std::cout << texte [i] << std::endl;
  }
  return 0;
}
