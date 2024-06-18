#include <iostream>
#include <string>
int main()
{
  for (int i{1}; i <= 6; i++)
  {
    std::string auteur{}, titre{};
    getline(std::cin, auteur);
    getline(std::cin, titre);
    std::cout << titre << std::endl;
    std::cout << auteur << std::endl;
  }
  return 0;
}
