#include <iostream>
#include <string>
#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbLivres{0};
  std::cin >> nbLivres;
  std::cin.ignore();
  std::string ligne{""}, palindrome{""}, ligneBis{""};
  for (int k{0}; k < nbLivres; k++)
  {
    getline(std::cin, ligne);
    for (int i{0}; i < (int)ligne.size(); i++)
    {
      if (ligne [i] != ' ')
      {
        ligneBis = ligneBis + (char)tolower(ligne [i]);
      }
    }
    for (int j{(int)ligneBis.size() - 1}; j >= 0; j--)
    {
      palindrome = palindrome + ligneBis [j];
    }
    if (palindrome == ligneBis)
    {
      std::cout << ligne << std::endl;
    }
    palindrome = "";
    ligneBis = "";
  }
  
  return 0;
}
