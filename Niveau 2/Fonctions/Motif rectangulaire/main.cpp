#include <iostream>
#include <string>
void dessin(int ligne, int colonne, char c)
{
  for (int i{1}; i <= ligne; i++)
  {
    for (int j{1}; j <= colonne; j++)
    {
      std::cout << c;
    }
    std::cout << std::endl;
  }
}
int main()
{
  int ligne{0}, colonne{0};
  char c;
  std::cin >> ligne >> colonne >> c;
  dessin(ligne, colonne, c);
  return 0;
}
