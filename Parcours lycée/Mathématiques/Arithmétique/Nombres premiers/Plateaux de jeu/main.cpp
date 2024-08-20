#include <iostream>
int main()
{
  int ligne, colonne;
  std::cin >> ligne >> colonne;
  char o {'O'};
  char x {'X'};
  for (int i {0}; i < ligne; ++i)
  {
    for (int j {0}; j < colonne; ++j)
    {
      if (!(j % 2))
        std::cout << o;
      else
        std::cout << x;
    }
    char t = o;
    o = x;
    x = t;
    std::cout << '\n';
  }
  return 0;
}
