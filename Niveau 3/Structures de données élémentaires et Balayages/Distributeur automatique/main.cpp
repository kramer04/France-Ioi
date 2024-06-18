#include <iostream>
#include <deque>
#include <algorithm>
struct In
{
  int deltaStj, date; //date de perémption , deltaStj variation du stock par rapport à la date de péremption
};
struct
{
  bool operator()(In a, In b) const
  {
    return a.date < b.date;
  }
} tri;
using Stock = std::deque<In>;
int main()
{
  std::ios::sync_with_stdio(false);
  int nbOperation{0};
  std::cin >> nbOperation;
  Stock stock;
  int j{-1};
  for (int i{0}; i < nbOperation; i++)
  {
    int quantite{0}, date{0};
    std::cin >> quantite >> date;
    if (quantite > 0)
    {
      stock.push_back({quantite, date});
      j++; //std::cout << "j -> " << j << " stock [" << j << "].deltaStj = " << stock [j].deltaStj << " stock [" << j << "].date = " << stock [j].date << "\n";
    }
    else
    {
      stock [0].deltaStj += quantite; //std::cout << "stock [" << j << "].deltaStj = " << stock [j].deltaStj << "\n";
      if (stock [0].deltaStj < 0)
      {
        int depassement = stock [0].deltaStj;
        stock.erase(stock.begin());
        j--;
        while (depassement < 0)
        {
          stock [0].deltaStj += depassement;
          depassement = stock [0].deltaStj;
          if (depassement < 0)
          {
            stock.erase(stock.begin());
            j--;
          }
          else if (stock [0].deltaStj == 0)
          {
            stock.erase(stock.begin());
            j--;
          }
        }
      }
      else if (stock [0].deltaStj == 0)
      {
        stock.erase(stock.begin());
        j--;
      }
    }
  }
  std::stable_sort(stock.begin(), stock.end(), tri);
  //[](const In &lhs, const In &rhs) {if (lhs.entree != 0 && rhs.entree != 0) return lhs.date < rhs.date; return false
  std::cout << stock [0].date << std::endl;
  return 0;
}
