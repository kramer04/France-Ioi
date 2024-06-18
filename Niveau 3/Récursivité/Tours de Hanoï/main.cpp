#include <iostream>
void hanoi(int n, int d, int i, int a);
int main()
{
  int n{0};
  std::cin >> n;
  hanoi(n, 1, 2, 3);
  return 0;
}
void hanoi(int n, int d, int i, int a)
{
  if (n == 1)
    std::cout << d << " -> " << a << "\n";
  else
  {
    hanoi(n - 1, d, a, i);
    hanoi(1, d, i, a);
    hanoi(n - 1, i, d, a);
  }
}
