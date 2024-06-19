#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    
    std::vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> values[i];
    }
    
    const int OFFSET = 100000; // Pour décaler les valeurs négatives
    const int RANGE = 200001;  // Plage de valeurs de -100000 à 100000
    
    std::vector<int> count(RANGE, 0); // Tableau de comptage initialisé à 0
    
    // Remplir le tableau de comptage
    for (int i = 0; i < N; ++i) {
        count[values[i] + OFFSET]++;
    }
    
    // Afficher les valeurs triées
    bool first = true;
    for (int i = 0; i < RANGE; ++i) {
        while (count[i]-- > 0) {
            if (first) {
                first = false;
            } else {
                std::cout << " ";
            }
            std::cout << (i - OFFSET);
        }
    }
    std::cout << std::endl;
    
    return 0;
}
