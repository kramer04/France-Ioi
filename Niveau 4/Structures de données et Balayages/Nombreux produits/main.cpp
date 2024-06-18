#include <iostream>
#include <list>
struct Date
{
  int nbArticles, date;
};
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbDistributeurs {0}, nbOperations {0};
  std::cin >> nbDistributeurs >> nbOperations;
  std::list<Date>distributeurs [nbDistributeurs + 1];
  for (int i {0}; i < nbOperations; i++)
  {
    int distributeur {0}, quantite {0}, date {0};
    std::cin >> distributeur >> quantite >> date;
    if (quantite > 0)
      distributeurs [distributeur].push_back({quantite, date});
    else
    {
      while (quantite != 0)
      {
        int tmp {distributeurs [distributeur].front().nbArticles};
        if (tmp > std::abs(quantite))
        {
          distributeurs [distributeur].front().nbArticles = (tmp + quantite);
          quantite = 0;
        }
        else
        {
          quantite = tmp + quantite;
          distributeurs [distributeur].pop_front();
        }
      }
    }
  }
  for (int i {1}; i <= nbDistributeurs; i++)
  {
    if (distributeurs [i].empty())
      std::cout << 0 << '\n';
    else
    {
      int reste {distributeurs [i].front().date};
      while (!distributeurs [i].empty())
      {
        int r {distributeurs [i].front().date};
        distributeurs [i].pop_front();
        if (r < reste)
          reste = r;
      }
      std::cout << reste << '\n';
    }
  }
  return 0;
}
