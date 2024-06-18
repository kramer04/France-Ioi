#include <iostream>
#include <string>
//#include <sstream>
char decrypte(char c, std::string &cle, std::string &base);
int main()
{
  std::ios::sync_with_stdio(false);
  std::string cle{""}, texteCrypte{""}, sortie{""}, base{"abcdefghijklmnopqrstuvwxyz"};
  std::cin >> cle;
  std::cin.ignore();
  getline(std::cin, texteCrypte);
  char c{'a'};
  for (int i{0}; i < (int)texteCrypte.size(); i++)
  {
    c = texteCrypte [i];
    sortie += decrypte(c, cle, base);
  }
  std::cout << sortie << std::endl;
  return 0;
}
char decrypte(char c, std::string &cle, std::string &base)
{
  int count{0};
  char d{c};
  if (c >= 'A' && c <= 'Z')
  {
    c = tolower(c);
  }
  count = base.find(c);
  if (c >= 'a' && c <= 'z')
  {
    c = cle [count];
  }
  if (d >= 'A' && d <= 'Z')
  {
    c = toupper(c);
  }
  return c;
}
