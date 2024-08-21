#include <iostream>

int main()
{
  char lettre[3];
  std::cin >> lettre;

  int x1 = lettre [0] - 65;
  int x2 = lettre [1] - 65;
  int y1 = (11 * x1 + 3 * x2) % 26;
  int y2 = (7 * x1 + 4 * x2) % 26;

  std::cout << (char)(y1 + 'A') << (char)(y2 + 'A') << '\n';
  return 0;
}
