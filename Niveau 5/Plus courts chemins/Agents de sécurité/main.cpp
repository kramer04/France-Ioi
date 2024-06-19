#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
int main() {
    // Optimisation des entrées/sorties
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, A;
    std::cin >> N >> A;
    const int INF = std::numeric_limits<int>::max() / 2; // Utilisation d'une valeur infinie
    // Initialisation de la matrice des distances
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));
    // Distance de chaque intersection à elle-même est 0
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }
    // Lecture des sentiers et initialisation des distances directes
    for (int i = 0; i < A; ++i) {
        int u, v, l;
        std::cin >> u >> v >> l;
        --u; // Convertir en index 0-based
        --v; // Convertir en index 0-based
        dist[u][v] = l;
        dist[v][u] = l; // Graph non orienté
    }
    // Algorithme de Floyd-Warshall
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // Affichage de la matrice des distances
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) std::cout << ' ';
            if (dist[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << dist[i][j];
            }
        }
        std::cout << '\n';
    }
    return 0;
}
