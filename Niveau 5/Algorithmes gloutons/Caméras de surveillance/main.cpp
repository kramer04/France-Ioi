#include <iostream>
#include <vector>
#include <algorithm>
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 1) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
private:
    std::vector<int> parent;
    std::vector<int> rank;
};
int main() {
    std::ios::sync_with_stdio(false);
    int N, A;
    std::cin >> N >> A;
    std::vector<Edge> edges;
    for (int i = 0; i < A; ++i) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }
    std::sort(edges.begin(), edges.end());
    UnionFind uf(N + 1);  
    int totalCableLength = 0;
    for (const Edge& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            totalCableLength += edge.weight;
        }
    }
    std::cout << totalCableLength << std::endl;
    return 0;
}
