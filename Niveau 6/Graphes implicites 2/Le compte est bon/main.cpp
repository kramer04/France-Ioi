#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric> // std::accumulate
// Problème : compter combien de valeurs dans [0..999] sont atteignables
// à partir de N (<=6) plaques, en utilisant +, -, *, / (division entière exacte),
// et en n'utilisant chaque plaque au plus une fois.
// Soustraction : autorisée uniquement si le résultat est >= 0.
// Division : autorisée uniquement si elle tombe juste (reste 0).
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  if (!(std::cin >> N))
    return 0;
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i)
    std::cin >> v[i];
  const int ALL = 1 << N;
  // R[S] = ensemble des valeurs atteignables en utilisant exactement les plaques du sous-ensemble S
  std::vector<std::unordered_set<int>> R(ALL);
  // Cas de base : singletons
  for (int i = 0; i < N; ++i)
  {
    int m = 1 << i;
    R[m].insert(v[i]);
  }
  // DP sur tous les sous-ensembles non vides
  for (int S = 1; S < ALL; ++S)
  {
    // S est un singleton : déjà initialisé
    if ((S & (S - 1)) == 0)
      continue;
    // Énumérer toutes les sous-partitions non vides A | B de S, avec A<B pour casser les symétries
    // Parcours standard des sous-masques : A parcourt les sous-ensembles non vides de S
    for (int A = (S - 1) & S; A; A = (A - 1) & S)
    {
      int B = S ^ A;
      if (B == 0)
        continue;
      if (A > B)
        continue; // évite de traiter deux fois (A,B) et (B,A)
      const std::unordered_set<int> &LA = R[A];
      const std::unordered_set<int> &LB = R[B];
      if (LA.empty() || LB.empty())
        continue;
      // Combiner toutes les paires (x, y) avec les 4 opérations autorisées
      for (int x : LA)
      {
        for (int y : LB)
        {
          // Addition
          R[S].insert(x + y);
          // Multiplication
          R[S].insert(x * y);
          // Soustractions (résultat non négatif uniquement)
          if (x >= y)
            R[S].insert(x - y);
          if (y >= x)
            R[S].insert(y - x);
          // Divisions exactes uniquement
          if (y != 0 && x % y == 0)
            R[S].insert(x / y);
          if (x != 0 && y % x == 0)
            R[S].insert(y / x);
        }
      }
    }
  }
  // Marquer toutes les valeurs atteignables dans [0..999] par n'importe quel sous-ensemble non vide
  std::vector<char> seen(1000, 0);
  for (int S = 1; S < ALL; ++S)
  {
    for (int val : R[S])
    {
      if (0 <= val && val <= 999)
        seen[static_cast<std::size_t>(val)] = 1;
    }
  }
  // Compter
  int nbPossibles = std::accumulate(seen.begin(), seen.end(), 0);
  std::cout << nbPossibles << '\n';
  return 0;
}
