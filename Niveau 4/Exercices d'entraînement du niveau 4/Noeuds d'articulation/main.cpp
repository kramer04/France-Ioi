#include <iostream>
#include <vector>
#include <algorithm>
void dfs(int v, int parent, int& timer, std::vector<int>& tin, std::vector<int>& low, std::vector<bool>& visited, const std::vector<std::vector<int>>& adj, std::vector<bool>& is_articulation) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == parent) continue; // Ignorer l'arête vers le parent
        if (visited[to]) {
            // Mise à jour de low[v] pour les arêtes de retour
            low[v] = std::min(low[v], tin[to]);
        } else {
            dfs(to, v, timer, tin, low, visited, adj, is_articulation);
            low[v] = std::min(low[v], low[to]);
            if (low[to] >= tin[v] && parent != -1) {
                is_articulation[v] = true;
            }
            ++children;
        }
    }
    if (parent == -1 && children > 1) {
        is_articulation[v] = true;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, A;
    std::cin >> N >> A;
    std::vector<std::vector<int>> adj(N + 1);
    for (int i = 0; i < A; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> tin(N + 1, -1);
    std::vector<int> low(N + 1, -1);
    std::vector<bool> visited(N + 1, false);
    std::vector<bool> is_articulation(N + 1, false);
    int timer = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, -1, timer, tin, low, visited, adj, is_articulation);
        }
    }
    int articulation_count = 0;
    for (int i = 1; i <= N; ++i) {
        if (is_articulation[i]) {
            ++articulation_count;
        }
    }
    std::cout << articulation_count << std::endl;
    return 0;
}
