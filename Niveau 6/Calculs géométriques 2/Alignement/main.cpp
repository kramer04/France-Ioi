#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // Lire le nombre d'arbres
    int A;
    std::cin >> A;
    
    // Lire les coordonnées des arbres
    std::vector<std::pair<int, int>> arbres(A);
    for (int i = 0; i < A; ++i) {
        std::cin >> arbres[i].first >> arbres[i].second;
    }
    // Si le nombre d'arbres est 0 ou 1, le plus grand alignement est le nombre d'arbres lui-même
    if (A <= 1) {
        std::cout << A << "\n";
        return 0;
    }
    int maxAlignes = 0;
    // Parcourir chaque arbre pour trouver le maximum d'arbres alignés
    for (int i = 0; i < A; ++i) {
        std::unordered_map<double, int> penteMap;
        int duplicata = 1;
        int vertical = 0;
        for (int j = i + 1; j < A; ++j) {
            if (arbres[i] == arbres[j]) {
                ++duplicata;
            } else if (arbres[i].first == arbres[j].first) {
                ++vertical;
            } else {
                double pente = static_cast<double>(arbres[j].second - arbres[i].second) /
                               static_cast<double>(arbres[j].first - arbres[i].first);
                ++penteMap[pente];
            }
        }
        maxAlignes = std::max(maxAlignes, vertical + duplicata);
        for (auto it = penteMap.begin(); it != penteMap.end(); ++it) {
            maxAlignes = std::max(maxAlignes, it->second + duplicata);
        }
    }
    // Afficher le résultat
    std::cout << maxAlignes << "\n";
    return 0;
}
