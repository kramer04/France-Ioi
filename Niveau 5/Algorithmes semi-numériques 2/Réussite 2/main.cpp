#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> valid_divisors;
  // Trouver tous les diviseurs
  for (int i = 2; i <= sqrt(N); ++i)
  {
    if (N % i == 0)
    {
      int quotient = N / i;
      if (quotient >= 2)
      {
        valid_divisors.push_back(i);
      }
      if (i >= 2 && i != quotient)
      {
        valid_divisors.push_back(quotient);
      }
    }
  }
  // Trier les diviseurs dans l'ordre croissant
  sort(valid_divisors.begin(), valid_divisors.end());
  // Afficher le résultat
  if (valid_divisors.empty())
  {
    std::cout << 0 << '\n';
  }
  else
  {
    for (int d : valid_divisors)
    {
      std::cout << d << '\n';
    }
  }
  return 0;
}
