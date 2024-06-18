#include <iostream>
#include <string>
int main()
{
  char c;
  std::cin >> c;
  int nbLignes{0}, nb{0};
  std::cin >> nbLignes;
  std::cin.ignore();
  for (int i{1}; i <= nbLignes; i++)
  {
    std::string ligne{""};
    getline(std::cin, ligne);
    for (int j{0}; j < (int)ligne.size(); j++)
    {
      if (ligne [j] == c)
      {
        nb++;
      }
    }
  }
  std::cout << nb << std::endl;
  return 0;
}
