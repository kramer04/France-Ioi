#include <iostream>
#include <vector>
#include <algorithm>
const int COLUMNS = 100;
const int MAX_HEIGHT = 10000; // Une valeur suffisamment grande pour la simulation
// Représentation du cadre de jeu
std::vector<int> height(COLUMNS, 0); // Hauteurs actuelles des colonnes
int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        char orientation;
        int length, column;
        std::cin >> orientation >> length >> column;
        if (orientation == 'H') {
            // Trouver la hauteur maximale des colonnes où le bâton horizontal tombera
            int max_height = 0;
            for (int j = column; j < column + length; ++j) {
                if (j < COLUMNS) {
                    max_height = std::max(max_height, height[j]);
                }
            }
            // Mettre à jour les hauteurs des colonnes concernées
            for (int j = column; j < column + length; ++j) {
                if (j < COLUMNS) {
                    height[j] = max_height + 1;
                }
            }
        } else if (orientation == 'V') {
            // La hauteur où le bâton vertical tombera
            height[column] += length;
        }
    }
    // Trouver la hauteur maximale atteinte dans toutes les colonnes
    int max_height = *std::max_element(height.begin(), height.end());
    std::cout << max_height << std::endl;
    return 0;
}
