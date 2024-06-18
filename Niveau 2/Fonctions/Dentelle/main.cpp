#include <iostream>
#include <string>
void entree(int in, char c)
{
  for(int i{1};i<=in;i++)
  {
    std::cout << c;
  }
  std::cout << std::endl;
}
int main()
{
  int longueur{0};
  std::cin >> longueur;
  entree(longueur,'X');
  entree(longueur, '#');
  entree(longueur, 'i');
  return 0;
}
