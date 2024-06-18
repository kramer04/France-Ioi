#include <iostream>
void entier(int n, int m);
int main()
{
  int n{0}, m{0};
  std::cin >> n >> m;
  entier(n, m);
  return 0;
}
void entier(int n, int m)
{
  if (n == m)
  {
    std::cout << m << "\n";
  }
  else
  {
    std::cout << n << " ";
    entier(n + 1, m);
  }
}
