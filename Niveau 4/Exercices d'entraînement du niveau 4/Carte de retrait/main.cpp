#include <iostream>
#include <deque>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int h, p, n;
  std::cin >> h >> p >> n;
  std::deque<int> pile;
  int somme = 0;
  for (int i {0}; i < n; ++i)
  {
    int retrait;
    std::cin >> retrait;
    // Si la taille de la pile dépasse H, enlever l'élément le plus ancien
    if ((int)pile.size() == h)
    {
      somme -= pile.front();
      pile.pop_front();
    }
    // Vérifier si le retrait peut être effectué sans dépasser le plafond
    if (somme + retrait <= p)
    {
      somme += retrait;
      pile.push_back(retrait);
      std::cout << "1\n";
    }
    else
    {
      pile.push_back(0); // Ajout d'un 0 pour maintenir la taille de la pile
      std::cout << "0\n";
    }
  }
  return 0;
}
