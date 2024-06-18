#include <iostream>
#include <string>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string note;
  std::getline(std::cin, note);
  char m, n;
  size_t i {0};
  while (i < note.size())
  {
    m = note [i];
    n = note [i + 1];
    if (m == n)
    {
      note.erase(i, 2);
      i = -1;
    }
    i++;
    //std::cout << note << '\n';
  }
  std::cout << note << '\n';
  return 0;
}
