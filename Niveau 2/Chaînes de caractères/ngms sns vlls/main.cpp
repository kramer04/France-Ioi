#include <iostream>
#include <string>
int main()
{
  std::string titre{""};
  for (int j{1}; j <= 2; ++j)
  {
    //std::cout << "Titre" << std::endl;
    getline(std::cin, titre);
    int tailleTitre = (int)titre.size();
    for (int i = {0}; i < tailleTitre; i++)
    {
      if (titre [i] != 'A' && titre [i] != 'E' && titre [i] != 'I' && titre [i] != 'O' && titre [i] != 'U' && titre [i] != 'Y' && titre [i] != ' ')
      {
        std::cout << titre [i];
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
