#include <iostream>
#include <string>
int somme(std::string &nom);
int main()
{
  std::ios::sync_with_stdio(false);
  std::string nom1{""}, nom2{""};
  std::cin >> nom1 >> nom2;
  std::cout << somme(nom1) << " " << somme(nom2) << '\n';
  
  return 0;
}
int somme(std::string &nom)
{
  int taille{(int)nom.size()}, add{0};
  for (int i{0}; i < taille; i++)
  {
    add = add + (int)nom [i] - 65;
  }
  while (add >= 10)
  {
    std::string s{std::to_string(add)};
    taille = s.size();
    add = 0;
    for (int i{0}; i < taille; i++)
    {
      add = add + (int)s [i] - 48;
    }
  }
  
  return add;
}
