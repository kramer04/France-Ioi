#include <iostream>
int main()
{
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int resultat = 1;
  for (int i = 0; i < n; i++)
  {
    int m;
    std::cin >> m;
    resultat = (resultat * (m % 10000)) % 10000;
  }
  std::cout.width(4);
  std::cout.fill('0');
  std::cout << resultat << std::endl;
  return 0;
}
