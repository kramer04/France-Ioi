#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
// Fonction pour effectuer un tri topologique
void topologicalSort(int v, std::vector<bool>& visited, std::stack<int>& Stack, const std::vector<std::vector<int>>& adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            topologicalSort(u, visited, Stack, adj);
        }
    }
    Stack.push(v);
}
// Fonction principale pour compter les chemins dans un DAG
int countPaths(int nbIntersections, const std::vector<std::vector<int>>& adj) {
    std::stack<int> Stack;
    std::vector<bool> visited(nbIntersections + 1, false);
    // Appliquer le tri topologique à tous les nœuds
    for (int i = 1; i <= nbIntersections; ++i) {
        if (!visited[i]) {
            topologicalSort(i, visited, Stack, adj);
        }
    }
    // Initialiser le nombre de chemins avec 0
    std::vector<int> pathCount(nbIntersections + 1, 0);
    pathCount[1] = 1;  // Le point de départ a un chemin vers lui-même
    // Processus les nœuds dans l'ordre topologique
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        if (pathCount[u] > 0) {
            for (int v : adj[u]) {
                pathCount[v] += pathCount[u];
                if (pathCount[v] >= 1000000000) { // Assurer que le nombre reste dans les limites
                    pathCount[v] -= 1000000000;
                }
            }
        }
    }
    return pathCount[nbIntersections];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int nbIntersections, nbRuisseaux;
    std::cin >> nbIntersections >> nbRuisseaux;
    std::vector<std::vector<int>> adj(nbIntersections + 1);
    for (int i = 0; i < nbRuisseaux; ++i) {
        int inter1, inter2;
        std::cin >> inter1 >> inter2;
        adj[inter1].emplace_back(inter2);
    }
    int result = countPaths(nbIntersections, adj);
    std::cout << result << std::endl;
    return 0;
}
