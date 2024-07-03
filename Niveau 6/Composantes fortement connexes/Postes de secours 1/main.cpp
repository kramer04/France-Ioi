// Algorithme de Kosaraju
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
class Graph {
public:
    Graph(int n) : adj(n), radj(n), scc_index(n, -1), n(n) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    void findSCCs() {
        // Étape 1 : Trouver tous les SCC à l'aide de l'algorithme de Kosaraju
        std::vector<bool> visited(n, false);
        std::stack<int> finishStack;
        // First pass: Order vertices by finish times
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs1(i, visited, finishStack);
            }
        }
        // Deuxième passage : Affectation des composants
        int scc_count = 0;
        visited.assign(n, false);
        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();
            if (!visited[v]) {
                dfs2(v, visited, scc_count++);
            }
        }
        // Step 2: Construire le graphique condensé
        std::vector<std::unordered_set<int>> condensedGraph(scc_count);
        std::vector<int> inDegree(scc_count, 0);
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                int scc_u = scc_index[u];
                int scc_v = scc_index[v];
                if (scc_u != scc_v && condensedGraph[scc_u].find(scc_v) == condensedGraph[scc_u].end()) {
                    condensedGraph[scc_u].insert(scc_v);
                    inDegree[scc_v]++;
                }
            }
        }
        // Étape 3 : Trouver les SCC ayant un degré de pénétration de 0
        std::vector<int> sources;
        for (int i = 0; i < scc_count; ++i) {
            if (inDegree[i] == 0) {
                sources.push_back(i);
            }
        }
        // Étape 4 : S'il existe exactement un SCC source, tous les sommets de ce SCC sont des points de sauvetage potentiels.
        if (sources.size() == 1) {
            for (int i = 0; i < n; ++i) {
                if (scc_index[i] == sources[0]) {
                    result.push_back(i);
                }
            }
        }
        // Trier le résultat pour qu'il corresponde au format de sortie attendu
        std::sort(result.begin(), result.end());
    }
    const std::vector<int>& getResult() const {
        return result;
    }
private:
    void dfs1(int v, std::vector<bool>& visited, std::stack<int>& finishStack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs1(u, visited, finishStack);
            }
        }
        finishStack.push(v);
    }
    void dfs2(int v, std::vector<bool>& visited, int scc_count) {
        visited[v] = true;
        scc_index[v] = scc_count;
        for (int u : radj[v]) {
            if (!visited[u]) {
                dfs2(u, visited, scc_count);
            }
        }
    }
    std::vector<std::vector<int>> adj, radj;
    std::vector<int> scc_index, result;
    int n;
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        graph.addEdge(A - 1, B - 1);
    }
    graph.findSCCs();
    const std::vector<int>& result = graph.getResult();
    std::cout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] + 1 << (i == result.size() - 1 ? "\n" : " ");
    }
    return 0;
}
