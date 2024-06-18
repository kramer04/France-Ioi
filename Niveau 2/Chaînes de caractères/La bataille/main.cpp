#include <iostream>
#include <string>
int main()
{
  std::string p1{""}, p2{""}, carte{""};
  getline(std::cin, p1);
  getline(std::cin, p2);
  int paire{0}, i{0};
  while (carte != "1" && carte != "2" && carte != "=")
  {
    if (p1 [i] == p2 [i])
    {
      paire++;
    }
    if ((p1 [i] < p2 [i]) || (p2.size() < p1.size() && i == (int)(p2.size() - 1)))
    {
      carte = '1';
      std::cout << carte << '\n' << paire << std::endl;
    }
    else if (i == ((int)p1.size() - 1) && p1.size() == p2.size())
    {
      carte = '=';
      std::cout << carte << '\n' << paire << std::endl;
    }
    else if ((p2 [i] < p1 [i]) || (p1.size() < p2.size() && i == (int)(p1.size() - 1)))
    {
      carte = '2';
      std::cout << carte << '\n' << paire << std::endl;
    }
    ++i;
  }
  return 0;
}
