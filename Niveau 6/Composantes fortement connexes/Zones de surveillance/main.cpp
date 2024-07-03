//Tarjan
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
class Graph {
public:
    Graph(int n) : adj(n), index(n, -1), lowlink(n, -1), onStack(n, false), currentIndex(0), n(n), sccCount(0) {}
    // Ajoute une arête dirigée de u vers v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    // Trouve tous les composants fortement connexes (SCC) dans le graphe
    void findSCCs() {
        for (int i = 0; i < n; ++i) {
            if (index[i] == -1) {
                strongConnect(i);
            }
        }
    }
    // Retourne le nombre de SCC trouvés
    int getSCCCount() const {
        return sccCount;
    }
private:
    // Fonction récursive utilisée par l'algorithme de Tarjan pour identifier les SCC
    void strongConnect(int v) {
        index[v] = currentIndex;
        lowlink[v] = currentIndex;
        currentIndex++;
        stack.push(v);
        onStack[v] = true;
        // Explore tous les voisins de v
        for (int w : adj[v]) {
            if (index[w] == -1) {
                strongConnect(w);
                lowlink[v] = std::min(lowlink[v], lowlink[w]);
            } else if (onStack[w]) {
                lowlink[v] = std::min(lowlink[v], index[w]);
            }
        }
        // Si v est une racine de SCC
        if (lowlink[v] == index[v]) {
            int w;
            do {
                w = stack.top();
                stack.pop();
                onStack[w] = false;
            } while (w != v);
            sccCount++;
        }
    }
    std::vector<std::vector<int>> adj; // Liste d'adjacence pour le graphe
    std::vector<int> index, lowlink; // Vecteurs pour l'index et lowlink
    std::vector<bool> onStack; // Marque si le noeud est sur la pile
    std::stack<int> stack; // Pile pour l'algorithme de Tarjan
    int currentIndex; // Index actuel pour Tarjan
    int n; // Nombre de noeuds dans le graphe
    int sccCount; // Nombre de SCC trouvés
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, A;
    std::cin >> N >> A;
    Graph graph(N);
    for (int i = 0; i < A; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.addEdge(u - 1, v - 1); // Convertit en index basé sur 0
    }
    graph.findSCCs();
    std::cout << graph.getSCCCount() << "\n";
    return 0;
}
