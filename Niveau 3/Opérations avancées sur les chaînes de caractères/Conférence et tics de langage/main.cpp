#include <iostream>
#include <string>
#include <sstream>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string phrase{""}, mot{""};
  std::cin >> mot;
  std::cin.ignore();
  getline(std::cin, phrase);
  std::istringstream iss{phrase};
  std::string word{""};
  int count{0};
  while (iss >> word)
  {
    word [0] = tolower (word [0]);
    if (word == mot)
    {
      count++;
    }
  }
  std::cout << count << std::endl;
  return 0;
}
