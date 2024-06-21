// code 5
#include <iostream>
#include <set>
#include <vector>
struct Command {
    int type;
    int value;
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int C;
    std::cin >> C;
    std::vector<Command> commands(C);
    std::vector<int> results;
    for (int i = 0; i < C; ++i) {
        std::cin >> commands[i].type >> commands[i].value;
    }
    std::multiset<int> values;
    for (int i = 0; i < C; ++i) {
        int type = commands[i].type;
        int value = commands[i].value;
        if (type == 1) {
            values.insert(value);
        } else if (type == 2) {
            auto it = values.find(value);
            if (it != values.end()) {
                values.erase(it);
            }
        } else if (type == 3) {
            auto it = values.lower_bound(value);
            if (it == values.begin()) {
                results.push_back(-1); // Aucun élément n'est strictement inférieur à value
            } else {
                --it;
                results.push_back(*it); // Le plus grand élément strictement inférieur à value
            }
        }
    }
    for (int result : results) {
        std::cout << result << "\n";
    }
    return 0;
}
