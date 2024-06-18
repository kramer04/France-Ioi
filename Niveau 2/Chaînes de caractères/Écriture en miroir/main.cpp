#include <iostream>
#include <string>
int main()
{
  std::string texte{""};
  int nbLignes{0};
  std::cin >> nbLignes;
  std::cin.ignore();
  
  for (int i{1}; i <= nbLignes; i++)
  {
    getline(std::cin, texte);
    int taille{(int)texte.size()};
    for (int i{taille - 1}; i >= 0; i--)
    {
      std::cout << texte [i];
    }
    std::cout << std::endl;
  }
  return 0;
}
