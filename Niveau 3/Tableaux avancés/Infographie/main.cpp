#include <iostream>
#include <vector>
using Grille = std::vector<std::vector<char>>;
void plaquage(Grille &tab, int x1, int y1, int x2, int y2, char c);
void affichage(Grille &tab, int l, int c);
int main()
{
  int nbLignes{0}, nbColonnes{0};
  std::cin >> nbLignes >> nbColonnes;
  Grille figure;
  for (int i{0}; i < nbLignes; i++)
  {
    figure.push_back(std::vector<char>(nbColonnes, '.'));
  }
  int x1{1}, y1{3}, x2{7}, y2{5}, nbRectangles{0};
  char c{'o'};
  std::cin >> nbRectangles;
  for (int i{0}; i < nbRectangles; i++)
  {
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> c;
    plaquage(figure, x1, y1, x2, y2, c);
  }
  affichage(figure, nbLignes, nbColonnes);
  return 0;
}
void plaquage(Grille &tab, int x1, int y1, int x2, int y2, char c)
{
  for (int i{x1}; i <= x2; i++)
  {
    for (int j{y1}; j <= y2; j++)
    {
      tab [i][j] = c;
    }
  }
}
void affichage(Grille &tab, int l, int c)
{
  for (int i{0}; i < l; i++)
  {
    for (int j{0}; j < c; j++)
    {
      std::cout << tab [i][j];
    }
    std::cout << "\n";
  }
}
