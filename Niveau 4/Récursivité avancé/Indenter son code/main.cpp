#include <iostream>
#include <string>
void indent(std::string &str, int level);
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::string str;
  getline(std::cin, str);
  indent(str, 0);
  return 0;
}
void indent(std::string &str, int level)
{
  if (str.empty())
    return;
  char c = str [0];
  str.erase(0, 1);
  if (c == '{')
  {
    for (int i {0}; i < level; i++)
    {
      std::cout << "   ";
    }
    std::cout << c << '\n';
    indent(str, level + 1);
  }
  else
  {
    for (int i {0}; i < level - 1; i++)
    {
      std::cout << "   ";
    }
    std::cout << "}" << '\n';
  }
  indent(str, level - 1);
}
