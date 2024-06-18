#include <iostream>
#include <string>
void affiche_ligne_pleine(int ligne, char c);
void affiche_rectangle(int ligne, int colonne);
void affiche_triangle(int ligne);
int main()
{
  int ligne{0}, rectangleL{0}, rectangleC{0}, triangle{0};
  std::cin >> ligne >> rectangleL >> rectangleC >> triangle;
  affiche_ligne_pleine(ligne, 'X');
  std::cout << std::endl;
  affiche_rectangle(rectangleL, rectangleC);
  std::cout << std::endl;
  affiche_triangle(triangle);
  return 0;
}
void affiche_ligne_pleine(int ligne, char c)
{
  for (int i{1}; i <= ligne; i++)
  {
    std::cout << c;
  }
  std::cout << std::endl;
}
void affiche_ligne_creuse(int ligne, char c)
{
  if (ligne == 1)
  {
    std::cout << c << std::endl;
  }
  else
  {
    std::cout << c;
    for (int i{2}; i <= ligne - 1; i++)
    {
      std::cout << ' ';
    }
    std::cout << c << std::endl;
  }
}
void affiche_rectangle(int ligne, int colonne)
{
  affiche_ligne_pleine(colonne, '#');
  for (int i{2}; i <= ligne - 1; i++)
  {
    affiche_ligne_creuse(colonne, '#');
  }
  affiche_ligne_pleine(colonne, '#');
}
void affiche_triangle(int ligne)
{
  std::cout << '@' << std::endl;
  for (int i{2}; i <= ligne - 1; i++)
  {
    affiche_ligne_creuse(i, '@');
  }
  affiche_ligne_pleine(ligne, '@');
}
