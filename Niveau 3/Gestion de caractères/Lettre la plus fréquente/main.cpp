#include <iostream>
#include <string>
//#include <cctype>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string ligne{""};
  int lettre [26]={0};
  int pos{0};
  char l{'A'};
  getline(std::cin, ligne);
  for (int i{0}; i <= 25; i++)
  {
    char c = i + 65;
    char d = i + 97;
    for (int j{0}; j < (int)ligne.size(); j++)
    {  
      if (ligne [j] == c || ligne [j] == d)
      {
        lettre [i]++;
      }
    }
    if (lettre [i] > pos)
    {
      pos = lettre [i];
      l = c;
    }
  }
  //std::sort(lettre, lettre + 26);
  std::cout << l << std::endl;
  return 0;
}
