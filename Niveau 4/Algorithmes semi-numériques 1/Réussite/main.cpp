#include <iostream>
#include <vector>
void eratosthene(int n)
{
  std::vector<bool> is_prime(n + 1, true);
  is_prime [0] = is_prime [1] = false;
  for (int i {2}; i * i <= n; i++)
  {
    if (is_prime [i])
      for (int j {i * i}; j <= n; j += i)
        is_prime [j] = false;
  }
  for (int i {7}; i <= n; i++)
  {
    if (is_prime [i])
      std::cout << i << '\n';
  }
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::cout << "0\n" << "1\n" << "2\n" << "3\n" << "5\n";
  eratosthene(n);
  return 0;
}
