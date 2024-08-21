#include <iostream>
int main()
{
  std::string lettre, sortie {""};
  std::cin >> lettre;
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  size_t t {lettre.size()};
  int x1, x2, y1, y2;
  for (size_t i {0}; i < t; i += 2)
  {
    x1 = (int) (lettre [i]) - 65;
    x2 = (int) (lettre) [i + 1] - 65;
    y1 = ((a * x1 + b * x2) % 26) + 65;
    y2 = ((c * x1 + d * x2) % 26) + 65;
    sortie += char(y1);
    sortie += char(y2);
  }
  std::cout << sortie << '\n';
  return 0;
}
