#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // Lire le nombre de lignes du triangle
    int r;
    std::cin >> r;
    // Déclarer une matrice pour stocker le triangle
    std::vector<std::vector<int>> triangle(r);
    // Lire le triangle
    for (int i = 0; i < r; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j < (int)triangle[i].size(); ++j) {
            std::cin >> triangle[i][j];
        }
    }
    // Algorithme dynamique pour trouver la plus grande somme
    for (int i = r - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    // La réponse est maintenant à la position [0][0]
    std::cout << triangle[0][0] << std::endl;
    return 0;
}
