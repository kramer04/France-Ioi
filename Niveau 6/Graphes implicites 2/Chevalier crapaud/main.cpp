#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    int start_row, start_col, end_row, end_col;
    std::cin >> start_row >> start_col;
    std::cin >> end_row >> end_col;
    std::vector<std::vector<char>> board(N, std::vector<char>(N));
    std::string line;
    for (int i = 0; i < N; ++i) {
        std::cin >> line;
        for (int j = 0; j < N; ++j) {
            board[i][j] = line[j];
        }
    }
    const std::vector<std::pair<int, int>> knight_moves = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    const std::vector<std::pair<int, int>> toad_moves = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    std::queue<std::tuple<int, int, int, bool>> q;
    std::vector<std::vector<char>> visited(N, std::vector<char>(N, 0));
    if (start_row >= 0 && start_row < N && start_col >= 0 && start_col < N && board[start_row][start_col] != '0') {
        q.push(std::make_tuple(start_row, start_col, 0, true));
        visited[start_row][start_col] = 0x01;  // Set bit pour chevalier
    }
    while (!q.empty()) {
        auto front = q.front();
        int row = std::get<0>(front), col = std::get<1>(front), steps = std::get<2>(front), is_knight = std::get<3>(front);
        q.pop();
        if (row == end_row && col == end_col) {
            std::cout << steps << "\n";
            return 0;
        }
        const auto& moves = is_knight ? knight_moves : toad_moves;
        char visit_mask = is_knight ? 0x02 : 0x01;  // Basculer entre chevalier et crapaud
        for (const auto& move : moves) {
            int new_row = row + move.first;
            int new_col = col + move.second;
            if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && board[new_row][new_col] != '0' && !(visited[new_row][new_col] & visit_mask)) {
                visited[new_row][new_col] |= visit_mask;
                q.push(std::make_tuple(new_row, new_col, steps + 1, !is_knight));
            }
        }
    }
    std::cout << "-1\n"; // Pas de solution
    return 0;
}
