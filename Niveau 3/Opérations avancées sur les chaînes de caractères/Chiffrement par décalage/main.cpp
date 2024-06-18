#include <iostream>
#include <string>
//#include <sstream>
std::string decode(int cle, std::string &code);
int main()
{
  int nbPages{0}, decalage{0};
  std::cin >> nbPages;
  std::cin.ignore();
  std::string phrase{""};
  for (int i{2}; i <= nbPages; i++)
  {
    getline(std::cin, phrase);
    if (i % 2 == 0)
    {
      decalage = 3 * i;
    }
    else
    {
      int d{-5 * i}; //5 * i - i - 1;
      if (abs(d) > 0 && abs(d) < 26)
      {
        decalage = 26 - d;
      }
      decalage = 26 + d % 26;
    }
    std::cout << decode(decalage, phrase) << std::endl;
  }
  return 0;
}
std::string decode(int cle, std::string &code)
{
  std::string decode{};
  for (auto d : code)
  {
    char m{d};
    if (d >= 'A' && d <= 'Z')
    {
      d = tolower(d);
    }
    if (d >= 'a' && d <= 'z')
    {
      if (d - (abs(cle % 26)) < 97)
      {
        d = d + 26 - cle % 26; //122-96
        if (m >= 'A' && m <= 'Z')
        {
          d = toupper(d);
        }
      }
      else
      {
        d -= (abs(cle % 26));
        if (m >= 'A' && m <= 'Z')
        {
          d = toupper(d);
        }
      }
    }
    decode += d;
  }
  return decode;
}
