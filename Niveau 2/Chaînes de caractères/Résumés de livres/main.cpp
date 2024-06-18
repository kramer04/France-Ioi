#include <iostream>
#include <string>
int main()
{
  int nbLivres{0}, longueurMinimale{0};
  std::cin >> nbLivres >> longueurMinimale;
  std::cin.ignore();
  std::string titre{""}, resume{""};
  for (int i{1}; i <= nbLivres; i++)
  {
    getline(std::cin, titre);
    getline(std::cin, resume);
    if ((int)resume.size() < longueurMinimale)
    {
      std::cout << titre << std::endl;
    }
    
  }
  
  return 0;
}
