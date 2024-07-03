#include <iostream>
#include <vector>
struct Point {
    int x, y;
};
// Fonction pour vérifier si un point est à l'intérieur du polygone
bool estInterieur(const std::vector<Point>& polygone, const Point& point) {
    int n = polygone.size();
    bool interieur = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        int xi = polygone[i].x, yi = polygone[i].y;
        int xj = polygone[j].x, yj = polygone[j].y;
        // Vérifie si le point est sur le segment horizontal
        if (yi == yj && yi == point.y && point.x > std::min(xi, xj) && point.x < std::max(xi, xj)) {
            return true;
        }
        // Vérifie si le point est à l'intérieur du polygone en utilisant l'algorithme des rayons
        if ((yi > point.y) != (yj > point.y)) {
            double intersect = (double)(xj - xi) * (point.y - yi) / (yj - yi) + xi;
            if (point.x < intersect) {
                interieur = !interieur;
            }
        }
    }
    return interieur;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int A;
    std::cin >> A;
    std::vector<Point> polygone(A);
    // Lecture des points du polygone
    for (int i = 0; i < A; ++i) {
        std::cin >> polygone[i].x >> polygone[i].y;
    }
    int L;
    std::cin >> L;
    std::vector<Point> lieux(L);
    // Lecture des lieux à vérifier
    for (int i = 0; i < L; ++i) {
        std::cin >> lieux[i].x >> lieux[i].y;
    }
    // Détermination si chaque lieu est à l'intérieur ou à l'extérieur du polygone
    for (const auto& lieu : lieux) {
        std::cout << estInterieur(polygone, lieu) << std::endl;
    }
    return 0;
}
