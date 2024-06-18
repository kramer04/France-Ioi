#include <iostream>
void remplir(int n);
void enlever(int i)
{
  std::cout << i << '\n';
}
void poser(int i)
{
  std::cout << i << '\n';
}
void vider(int n)
{
  if (n == 1)
    enlever(1);
  else if (n > 1)
  {
    vider(n - 2);
    enlever(n);
    remplir(n - 2);
    vider(n - 1);
  }
}
void remplir(int n)
{
  if (n == 1)
    poser(1);
  else if (n > 1)
  {
    remplir(n - 1);
    vider(n - 2);
    poser(n);
    remplir(n - 2);
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int N;
  std::cin >> N;
  vider(N);
  return 0;
}
