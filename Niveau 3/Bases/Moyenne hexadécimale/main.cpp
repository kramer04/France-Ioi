#include <iostream>
#include <string>
#include <cmath>
//fonctions
int enBaseDix(std::string &str, int b1, int taille);
std::string enBaseN(int c, int b2);
int main()
{
  std::ios::sync_with_stdio(false);
  std::string nb{};
  int base{16};
  std::cin >> nb;
  int t{(int)nb.size()};
  int n{enBaseDix(nb, base, t)}, item{0};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> nb;
    t = (int)nb.size();
    item += enBaseDix(nb, base, t);
  }
  item /= n;
  std::cout << enBaseN(item, base) << std::endl;
  return 0;
}
//transformation de base N en base 10
int enBaseDix(std::string &str, int b1, int taille)
{
  int nb10{0}, tmp{0};
  char c{};
  for (int i{taille - 1}; i >= 0; --i)
  {
    c = str [i];
    (c >= 'A' && c <= 'F') ? tmp = c - 55 : tmp = c - 48;
    nb10 += tmp * (int)(pow(b1, (int)(taille - 1 - i)));
  }
  return nb10;
}
//transformation de base 10 en base N
std::string enBaseN(int c, int b2)
{
  int reste{0};
  char nb{};
  std::string division;
  while (c > 0)
  {
    reste = c % b2;
    (reste > 9) ? nb = (char)(reste + 55) : nb = (char)(reste + 48);
    division = nb + division;
    c /= b2;
  }
  return division;
}
