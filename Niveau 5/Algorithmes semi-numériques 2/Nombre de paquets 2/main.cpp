//code 3
#include <iostream>
#include <vector>
// Fonction récursive pour calculer le coefficient binomial C(n, k)
unsigned long long binomialCoefficient(int n, int k, std::vector<std::vector<unsigned long long>> &memo)
{
  // Cas de base
  if (k == 0 || k == n)
  {
    return 1;
  }
  // Vérifier si la valeur est déjà calculée
  if (memo [n][k] != 0)
  {
    return memo [n][k];
  }
  // Calcul récursif en utilisant la relation de Pascal
  unsigned long long result = binomialCoefficient(n - 1, k - 1, memo) + binomialCoefficient(n - 1, k, memo);
  // Stocker le résultat dans le tableau memoization pour une utilisation ultérieure
  memo [n][k] = result;
  return result;
}
// Fonction principale pour calculer le coefficient binomial C(n, k)
unsigned long long computeBinomialCoefficient(int n, int k)
{
  // Initialisation du tableau de mémoization
  std::vector<std::vector<unsigned long long>> memo(n + 1, std::vector<unsigned long long>(k + 1, 0));
  return binomialCoefficient(n, k, memo);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, P;
  std::cin >> N >> P;
  // Calcul du coefficient binomial C(N, P)
  unsigned long long result = computeBinomialCoefficient(N, P);
  // Affichage du résultat
  std::cout << result << '\n';
  return 0;
}
