#include <iostream>
#include <algorithm>
#include <vector>
using Vecteur = std::vector<int>;
template <typename T>
T entree(int e);
struct Operation
{
  int numProduit, quantite;
};
int main()
{
  std::ios::sync_with_stdio(false);
  int nbTypes{0};
  std::cin >> nbTypes;
  Vecteur stock = entree<Vecteur>(nbTypes);
  int nbOp{0};
  std::cin >> nbOp;
  Operation op;
  for (int i{0}; i < nbOp; i++)
  {
    std::cin >> op.numProduit >> op.quantite;
    stock [op.numProduit - 1] += op.quantite;
  }
  for (int i{0}; i < nbTypes; i++)
  {
    std::cout << stock [i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
template <typename T>
T entree(int e)
{
  T in;
  for (int i{0}; i < e; i++)
  {
    in.push_back(0);
    std::cin >> in [i];
  }
  return in;
}
