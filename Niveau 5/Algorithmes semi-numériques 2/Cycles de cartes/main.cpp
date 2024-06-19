#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> cards[i];
    }
    std::vector<bool> visited(N, false);
    std::vector<std::vector<int>> cycles;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            std::vector<int> cycle;
            int start = i;
            while (!visited[start]) {
                visited[start] = true;
                cycle.push_back(start + 1); // Collect indices (1-based)
                start = cards[start] - 1; // Move to the next index (0-based)
            }
            // Find the smallest value in the cycle to start with
            auto min_pos = std::min_element(cycle.begin(), cycle.end());
            std::rotate(cycle.begin(), min_pos, cycle.end());
            cycles.push_back(cycle);
        }
    }
    // Sort cycles based on the smallest element in each cycle
    std::sort(cycles.begin(), cycles.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });
    // Output the result
    std::cout << cycles.size() << std::endl;
    for (const auto& cycle : cycles) {
        for (int card : cycle) {
            std::cout << cards[card - 1] << " "; // Print the original values
        }
        std::cout << std::endl;
    }
    return 0;
}
