#include <iostream>
#include <cmath>
// Fonction pour calculer la puissance de P dans N!
unsigned long long powerOfPrimeInFactorial(int N, int P)
{
  unsigned long long count = 0;
  while (N > 0)
  {
    N /= P;
    count += N;
  }
  return count;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, P;
  std::cin >> N >> P;
  // Calcul de la puissance de P dans N!
  unsigned long long result = powerOfPrimeInFactorial(N, P);
  // Affichage du résultat
  std::cout << result << '\n';
  return 0;
}
