#include <iostream>
#include <string>
int main()
{
  int nbLignes{0};
  std::string texte{""};
  std::cin >> nbLignes;
  std::cin.ignore();
  for (int i{1}; i <= nbLignes; i++)
  {
  getline(std::cin, texte);
    if (i % 2 !=0)
    {
      std::cout << texte << std::endl;
    }
  }
  return 0;
}
