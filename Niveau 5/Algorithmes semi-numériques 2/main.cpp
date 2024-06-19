#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Fonction pour générer toutes les combinaisons de couleurs
void generateCombinations(int P, vector<int>& combinations) {
    int totalCombinations = (1 << P); // 2^P combinaisons
    for (int i = 1; i < totalCombinations; ++i) {
        combinations.push_back(i);
    }
}
// Fonction pour compter le nombre de bits à 1 dans un entier (nombre de couleurs dans une combinaison)
int countBits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}
int main() {
    int P;
    cin >> P;
    vector<int> combinations;
    generateCombinations(P, combinations);
    int totalCombinations = combinations.size();
    vector<int> responses(totalCombinations);
    // Lire les réponses pour chaque combinaison
    for (int i = 0; i < totalCombinations; ++i) {
        cin >> responses[i];
    }
    // Calculer le nombre total de cartes choisies en utilisant l'inclusion-exclusion
    int totalCards = 0;
    for (int i = 0; i < totalCombinations; ++i) {
        int bits = countBits(combinations[i]);
        if (bits % 2 == 1) {
            totalCards += responses[i];
        } else {
            totalCards -= responses[i];
        }
    }
    cout << totalCards << endl;
    return 0;
}
