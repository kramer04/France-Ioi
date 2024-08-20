#include <iostream>
int main()
{
  int nbCrapauds, nbCouleuvres, nbAnnees;
  std::cin >> nbCrapauds >> nbCouleuvres >> nbAnnees;
  for (int i {1}; i <= nbAnnees; i++)
  {
    int crapauds {nbCrapauds}, couleuvres {nbCouleuvres};
    std::cout << nbCrapauds << " " << nbCouleuvres << '\n';
    nbCrapauds = 3 * crapauds - 2 * couleuvres;
    nbCouleuvres = crapauds - couleuvres;
  }
  return 0;
}
