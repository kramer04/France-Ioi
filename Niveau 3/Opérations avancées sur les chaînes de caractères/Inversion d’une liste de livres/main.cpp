#include <iostream>
#include <string>
#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbLivres{0};
  std::cin >> nbLivres;
  std::string ligne [1000];
  std::cin.ignore();
  for (int i{0}; i < nbLivres; i++)
  {
    getline(std::cin, ligne [i]);
  }
  for (int i{0}; i < nbLivres/2; i++)
  {
    std::string s{ligne [nbLivres - i - 1]};
    ligne [nbLivres - i - 1] = ligne [i];
    ligne [i] = s;
  }
  for (int i{0}; i < nbLivres; i++)
  {
    std::cout << ligne [i] << '\n';
  }
  return 0;
}
