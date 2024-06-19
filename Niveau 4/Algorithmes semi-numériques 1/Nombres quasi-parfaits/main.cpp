#include <iostream>
#include <vector>
int main()
{
  int L, D;
  std::cin >> L >> D;
  std::vector<int> sum_of_divisors(L + 1, 0); // tableau pour stocker les sommes de diviseurs
  // crible d'Eratosthène pour générer les diviseurs
  for (int i = 1; i <= L; i++)
    for (int j = i * 2; j <= L; j += i)
      sum_of_divisors [j] += i;
  // compter le nombre de nombres quasi parfaits
  int count = 0;
  for (int i = 1; i <= L; i++)
  {
    int diff = abs(sum_of_divisors [i] - i);
    if (diff <= D)
      count++;
  }
  std::cout << count << '\n';
  return 0;
}
