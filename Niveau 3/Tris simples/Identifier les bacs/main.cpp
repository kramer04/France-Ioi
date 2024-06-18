// voir le tri à bulle
#include <iostream>
#include <algorithm>
#include <vector>
struct Tri
{
  int index, pollution;
};
struct
{
  bool operator()(Tri a, Tri b) const { return a.pollution < b.pollution; }
} customLess;
int main()
{
  std::ios::sync_with_stdio(false);
  int nbBacs{0};
  std::cin >> nbBacs;
  
  std::vector<Tri> bac;
  for (int i{0}; i < nbBacs; i++)
  {
    int id{0}, p{0};
    std::cin >> id >> p;
    bac.push_back({id, p});
  }
  std::sort(bac.begin(), bac.end(), [](const Tri &id, const Tri &p) {return id.index < p.index; });
  std::stable_sort(bac.begin(), bac.end(), customLess);
  for (int i{0}; i < nbBacs; i++)
  {
    std::cout << bac [i].index << " " << bac [i].pollution << "\n";
  }
  return 0;
}
