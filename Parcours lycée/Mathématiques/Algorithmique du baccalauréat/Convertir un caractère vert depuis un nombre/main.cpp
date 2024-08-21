#include <iostream>
int main()
{
  char lettre;
  int n;
  std::cin >> lettre >> n;
  std::cout << lettre - 'A' << '\n' << (char) (n + 'A') << '\n';
  return 0;
}
