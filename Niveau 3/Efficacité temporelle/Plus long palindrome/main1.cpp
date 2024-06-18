#include <iostream>
#include <string>
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
int pal(std::string &p, int gauche, int droite)
{
  int maximum {0};
  int taille = int(p.size());
  while (gauche >= 0 && droite < taille && p [gauche] == p [droite])
  {
    gauche--;
    droite++;
    maximum = droite - gauche - 1;
  }
  return maximum;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::string palyndrome;
  std::cin >> palyndrome;
  int maximum {1};
  for (int i {0}; i < int(palyndrome.size()); i++)
  {
    //impair
    maximum = max_f(maximum, pal(palyndrome, i - 1, i + 1));
    //pair
    maximum = max_f(maximum, pal(palyndrome, i, i + 1));
  }
  std::cout << maximum << '\n';
  return 0;
}
//mollakayakokomassa
