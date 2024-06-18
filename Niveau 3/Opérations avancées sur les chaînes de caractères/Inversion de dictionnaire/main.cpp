#include <iostream>
#include <string>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbMots{0};
  std::cin >> nbMots;
  std::cin.ignore();
  std::string mot1 [100], mot2 [100], s1{""}, s2{""};
  for (int i{0}; i < nbMots; i++)
  {
    std::cin >> mot1 [i] >> mot2 [i];
  }
  for (int i{1}; i <= nbMots; i++)
  {
    for (int j{1}; j < nbMots; j++)
    {
      if (mot2 [j] < mot2 [j - 1])
      {
        s1 = mot1 [j - 1];
        s2 = mot2 [j - 1];
        mot1 [j - 1] = mot1 [j];
        mot2 [j - 1] = mot2 [j];
        mot1 [j] = s1;
        mot2 [j] = s2;
      }
    }
  }
  //std::sort(mot1, mot1 + nbMots);
  //std::sort(mot2, mot2 + nbMots);
  //std::cout << "-------------\n";
  for (int i{0}; i < nbMots; i++)
  {
    std::cout << mot2 [i] << " " << mot1 [i] << '\n';
  }
  return 0;
}
