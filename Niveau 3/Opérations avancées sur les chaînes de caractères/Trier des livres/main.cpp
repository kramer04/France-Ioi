#include <iostream>
#include <string>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbLivres{0};
  std::cin >> nbLivres;
  std::cin.ignore();
  std::string line [100];
  for (int i{0}; i < nbLivres; i++)
  {
    getline(std::cin, line[i]);
  }
  std::sort(line, line + nbLivres);
  for (int i{0}; i < nbLivres; i++)
  {
    std::cout << line [i] << '\n';
  }
  return 0;
}
