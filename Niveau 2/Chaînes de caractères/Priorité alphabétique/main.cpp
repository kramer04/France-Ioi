#include <iostream>
#include <string>
int main()
{
  std::string auteur1{}, auteur2{};
  std::cin >> auteur1 >> auteur2;
  if (auteur1 < auteur2)
  {
    std::cout << auteur1 << std::endl;
  }
  else if(auteur2<auteur1)
  {
    std::cout << auteur2 << std::endl;
  }
  else
  {
    std::cout << std::endl;
  }
  return 0;
}
