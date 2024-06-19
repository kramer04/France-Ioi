#include <iostream>
#include <set>
void insertValue(std::multiset<int>& pq, int value) {
    pq.insert(value);
}
void extractMin(std::multiset<int>& pq) {
    if (pq.empty()) {
        std::cout << "-" << std::endl;
    } else {
        auto it = pq.begin();
        std::cout << *it << std::endl;
        pq.erase(it);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int R;
    std::cin >> R;
    std::multiset<int> pq;
    for (int i = 0; i < R; ++i) {
        char query;
        std::cin >> query;
        if (query == 'I') {
            int value;
            std::cin >> value;
            insertValue(pq, value);
        } else if (query == 'E') {
            extractMin(pq);
        }
    }
    return 0;
}
