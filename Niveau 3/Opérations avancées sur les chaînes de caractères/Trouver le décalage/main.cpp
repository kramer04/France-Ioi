#include <iostream>
#include <string>
#include <array>
#include <algorithm>
struct Bloc
{
  int indice{0};
  int nb{0};
};
std::array<Bloc, 25> tFrequence{};
std::string decode(int cle, std::string &code);
int frequence(std::string &ligne);
int main()
{
  std::string phrase{""};
  std::array<std::string, 25> dPhrase{""};
  getline(std::cin, phrase);
  for (int i{1}; i < 26; i++)
  {
    dPhrase [i - 1] = decode(i, phrase); //std::cout << "dPhrase -> " << dPhrase[i-1] << std::endl;
    tFrequence [i - 1].indice = i - 1;
    tFrequence [i - 1].nb = frequence(dPhrase [i - 1]);
  }
  std::sort(std::begin(tFrequence), std::end(tFrequence), [](Bloc &lhs, Bloc &rhs) {return lhs.nb > rhs.nb; });

  std::cout << dPhrase[tFrequence[0].indice] << std::endl;

  return 0;
}
std::string decode(int cle, std::string &code)
{
  std::string decode{""};
  for (char d : code)
  {
    char m{d};
    if (d >= 'A' && d <= 'Z')
    {
      d = tolower(d);
    }
    if (d >= 'a' && d <= 'z')
    {
      if (d - cle % 26 < 97)
      {
        d = d + 26 - cle % 26; //122-96
        if (m >= 'A' && m <= 'Z')
        {
          d = toupper(d);
        }
      }
      else
      {
        d -= cle % 26;
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
int frequence(std::string &ligne)
{
  int count{0};
  for (int i{0}; i < (int)ligne.size(); i++)
  {
    if (ligne [i] == 'e' || ligne [i] == 'E')
    {
      count++;
    }
  }
  return count;
}
