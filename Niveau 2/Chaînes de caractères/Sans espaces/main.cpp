#include <iostream>
#include <string>
int main()
{
  std::string ligne{""};
  getline(std::cin, ligne);
  int taille{(int)ligne.size()};
  for (int i{0}; i < taille; i++)
  {
    if (ligne [i] == ' ')
    {
      ligne [i] = '_';
    }
  }
  std::cout << ligne << std::endl;
  return 0;
}
