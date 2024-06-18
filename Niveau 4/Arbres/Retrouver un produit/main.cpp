#include <iostream>
#include <string>
#include <vector>
void cherche(std::vector<int> &cont, std::vector<int> &obj, int j);
int main()
{
  std::ios::sync_with_stdio(false);
  int nb{0};//nombre de produits et récipients de la réserve, identifiés par un code.
  std::cin >> nb;
  std::vector<int> contenant(20000);
  for (int i{0}; i < nb; i++)
    std::cin >> contenant [i];
  int R{0};
  std::cin >> R;
  std::vector<int> objet(R);
  for (int i{0}; i < R; i++)
    std::cin >> objet [i];
  for (int i{0}; i < R; i++)
  {
    cherche(contenant, objet, objet [i]);
    std::cout << std::endl;
  }
  return 0;
}
void cherche(std::vector<int> &cont, std::vector<int> &obj, int j)
{
  if (j == 0)return;
  cherche(cont, obj, cont [j-1]);
  std::cout << j << " ";
}
