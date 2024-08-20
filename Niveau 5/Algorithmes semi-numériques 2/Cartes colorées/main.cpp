// https://www.france-ioi.org/algo/task.php?idChapter=541&iOrder=4
/*
Exemple
Entrée
2
2 2 1 
Sortie
3
*/
#include <iostream>
#include <vector>
#include <cmath>

// Fonction pour générer toutes les combinaisons de couleurs
void generateCombinations(int P, std::vector<int> &combinations)
{
  int totalCombinations = (1 << P); // 2^P combinaisons
  for (int i = 1; i < totalCombinations; ++i)
  {
    combinations.push_back(i);
  }
}
// Fonction pour compter le nombre de bits à 1 dans un entier (nombre de couleurs dans une combinaison)
int countBits(int x)
{
  int count = 0;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }
  return count;
}
int main()
{
  int P;
  std::cin >> P;
  std::vector<int> combinations;
  generateCombinations(P, combinations);
  int totalCombinations = combinations.size();
  std::vector<int> responses(totalCombinations);

  // Lire les réponses pour chaque combinaison
  for (int i = 0; i < totalCombinations; ++i)
  {
    std::cin >> responses [i];
  }
  
  // Calculer le nombre total de cartes choisies en utilisant l'inclusion-exclusion
  int totalCards = 0;
  for (int i = 0; i < totalCombinations; ++i)
  {
    int bits = countBits(combinations [i]);
    if (bits % 2 == 1)
    {
      totalCards += responses [i];
    }
    else
    {
      totalCards -= responses [i];
    }
  }
  std::cout << totalCards << '\n';
  return 0;
}
