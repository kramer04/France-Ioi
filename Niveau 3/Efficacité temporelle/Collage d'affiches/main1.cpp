#include <iostream>
#include <stack>
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
int empiler(std::stack<int> &pile, int hauteur, int indice)
{
  pile.push(hauteur);
  indice++;
  return indice;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nbRequetes;
  std::cin >> nbRequetes;
  char question;
  int hauteur {0}, maxHauteur {0}, indice {0};
  std::stack<int>pile;
  for (int i {0}; i < nbRequetes; i++)
  {
    std::cin >> question;
    if (question == 'C')
    {
      std::cin >> hauteur;
      maxHauteur = max_f(hauteur, maxHauteur);
      if (!pile.empty() && hauteur >= pile.top() && hauteur < maxHauteur)
      {
        while (hauteur >= pile.top())
        {
          pile.pop();
          indice--;
        }
        indice = empiler(pile, hauteur, indice);
      }
      else if (hauteur < maxHauteur)
      {
        indice = empiler(pile, hauteur, indice);
      }
      else
      {
        indice = 0;
        while(!pile.empty())
          pile.pop();
        indice = empiler(pile, hauteur, indice);
      }
    }
    else if (question == 'Q')
      std::cout << indice << '\n';
  }
  return 0;
}
