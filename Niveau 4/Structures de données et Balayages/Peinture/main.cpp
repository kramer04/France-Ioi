#include <iostream>
#include <map>
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbQuantites {0}, quantiteRecherchee {0};
  std::cin >> nbQuantites >> quantiteRecherchee;
  std::map<int, int>liste;
  int quantite {0};
  for (int i {0}; i < nbQuantites; ++i)
  {
    std::cin >> quantite;
    if (quantite * 2 == quantiteRecherchee)
    {
      std::cout << "OUI" << '\n';
      return 0;
    }
    else
      liste [quantite] = quantiteRecherchee - quantite;
  }
  auto it = liste.begin();
  for (; it != liste.end(); ++it)
  {
    if (liste.find(it->second) != liste.end())
    {
      std::cout << "OUI" << '\n';
      return 0;
    }
      
  }
  std::cout << "NON" << '\n';
  return 0;
}
