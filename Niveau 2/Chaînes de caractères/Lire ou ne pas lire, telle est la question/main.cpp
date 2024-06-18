#include <iostream>
#include <string>
int main()
{
  int nbLivres{0};
  std::cin >> nbLivres;
  std::cin.ignore();
  std::string titre{""};
  getline(std::cin, titre);
  std::string titrePrecedent{titre};
  std::cout << titre << std::endl;
  for (int i{2}; i <= nbLivres; i++)
  {
    
    getline(std::cin, titre);
    
    if (titre.size() > titrePrecedent.size())
    {
      std::cout << titre << std::endl;
      titrePrecedent = titre;
    }
  }
  
  return 0;
}
