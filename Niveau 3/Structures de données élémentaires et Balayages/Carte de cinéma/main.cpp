#include <iostream>
#include <vector>
#include <algorithm>
struct Indice
{
  int ticket, id;
};
int main()
{
  int nbClient{0};
  std::cin >> nbClient;
  std::vector<Indice> ticket;
  std::vector<Indice> copie;
  for (int i{0}; i < nbClient; i++)
  {
    ticket.push_back({0, i});
    std::cin >> ticket [i].ticket;
  }
  copie = ticket;
  std::stable_sort(begin(ticket), end(ticket), [](const Indice &lhs, const Indice &rhs) {return lhs.ticket < rhs.ticket; });
  std::vector<Indice>::iterator tricheur;
  int smallIdc{nbClient};
  bool paire{false};
  for (int k{0}; k < nbClient; ++k)
  {
    tricheur = std::adjacent_find(begin(ticket) + k, end(ticket), [](const Indice &lhs, const Indice &rhs) {return lhs.ticket == rhs.ticket; });
    if (tricheur != end(ticket) && tricheur [1].id < smallIdc)
    {
      smallIdc = tricheur [1].id;
      paire = true;
    }
    k = std::distance(begin(ticket), tricheur);
  }
  if (paire)
    std::cout << copie [smallIdc].ticket << std::endl;
  else
  {
    std::cout << -1 << std::endl;
  }
  return 0;
}
