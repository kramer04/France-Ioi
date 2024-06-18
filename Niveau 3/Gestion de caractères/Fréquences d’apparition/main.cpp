#include <iostream>
#include <string>
#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string ligne{""};
  getline(std::cin, ligne);
  for (int i{0}; i < (int)ligne.size(); i++)
  {
    ligne [i] = std::tolower((char)ligne [i]);
  }
  int count{0};
  for (int i{0}; i < (int)ligne.size(); i++)
  {
    if (isalpha(ligne [i]))
    {
      count++;
    }
  }
  for (int i{97}; i < 123; i++)
  {
    int nb{0};
    char c = i;
    for (int j{0}; j < (int)ligne.size(); j++)
    {
      if (c == ligne [j])
      {
        nb++;
      }
    }
    std::cout << (double)nb / count << '\n';
  }
  return 0;
}
