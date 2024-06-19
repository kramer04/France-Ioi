#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
struct SegmentTree {
    std::vector<int> tree;
    int n;
    SegmentTree(int size) {
        n = size;
        tree.resize(2 * n, -1); // Initialiser avec -1, car les indices sont >= 0
    }
    void update(int pos, int value) {
        pos += n;
        if (value == 1) {
            tree[pos] = pos - n; // stocker l'indice
        } else {
            tree[pos] = -1; // réinitialiser à -1
        }
        while (pos > 1) {
            pos /= 2;
            tree[pos] = std::max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }
    int query(int l, int r) {
        l += n;
        r += n;
        int max_val = -1;
        while (l <= r) {
            if (l % 2 == 1) {
                max_val = std::max(max_val, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                max_val = std::max(max_val, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return max_val;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    int N, R;
    std::cin >> N >> R;
    SegmentTree st(N);
    char query_type;
    int Ki, Vi;
    for (int i = 0; i < R; ++i) {
        std::cin >> query_type;
        if (query_type == 'M') {
            std::cin >> Ki >> Vi;
            st.update(Ki, Vi);
        } else if (query_type == 'R') {
            std::cin >> Ki;
            int result = st.query(0, Ki);
            std::cout << result << "\n";
        }
    }
    return 0;
}
