#include <iostream>
#include <string>
#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  int nb{0};
  std::cin >> nb;
  std::cin.ignore();
  for (int k{0}; k < nb; ++k)
  {
    std::string nom{""};
    std::cin >> nom;
    bool yesNo = (isalpha(nom [0]) || nom [0] == '_');
    if (yesNo)
    {
      int i{1};
      while (yesNo && i < (int)nom.size())
      {
        yesNo = (isalpha(nom [i]) || nom [i] == '_' || isdigit(nom [i]));
        i++;
      }
    }
    yesNo ? std::cout << "YES\n" : std::cout << "NO\n";
  }
  return 0;
}
