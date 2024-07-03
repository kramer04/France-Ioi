#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio> // Pour utiliser printf et scanf
// Structure pour représenter un point
struct Point {
    double x, y;
};
// Fonction pour calculer la distance au carré entre deux points
double distanceCarree(double x1, double y1, double x2, double y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
// Fonction pour déterminer l'orientation de trois points (p, q, r)
int orientation(const Point& p, const Point& q, const Point& r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinéaire
    return (val > 0) ? 1 : 2; // horaire ou anti-horaire
}
// Fonction de comparaison pour le tri des points par angle
bool compare(const Point& p1, const Point& p2) {
    if (p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}
// Fonction pour construire le convex hull utilisant l'algorithme de Graham scan
std::vector<Point> convexHull(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};
    // Tri des points par coordonnées
    std::sort(points.begin(), points.end(), compare);
    std::vector<Point> hull;
    // Construire la partie inférieure du hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    // Construire la partie supérieure du hull
    size_t t = hull.size() + 1;
    for (int i = n - 1; i >= 0; --i) {
        while (hull.size() >= t && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    // Supprimer le dernier point car il est le même que le premier point
    hull.pop_back();
    return hull;
}
// Fonction pour trouver la distance maximale utilisant les calipers rotatifs
double rotatingCalipers(const std::vector<Point>& hull) {
    int m = hull.size();
    if (m == 1) return 0;
    int k = 1;
    double maxDistance = 0;
    for (int i = 0; i < m; i++) {
        while (true) {
            double dist1 = distanceCarree(hull[i].x, hull[i].y, hull[(k + 1) % m].x, hull[(k + 1) % m].y);
            double dist2 = distanceCarree(hull[i].x, hull[i].y, hull[k].x, hull[k].y);
            if (dist1 > dist2) {
                k = (k + 1) % m;
            } else {
                break;
            }
        }
        double dist = std::sqrt(distanceCarree(hull[i].x, hull[i].y, hull[k].x, hull[k].y));
        if (dist > maxDistance) {
            maxDistance = dist;
        }
    }
    return maxDistance;
}
int main() {
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    int S;
    std::scanf("%d", &S);
    std::vector<Point> points(S);
    for (int i = 0; i < S; ++i) {
        std::scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    // Trouver le convex hull
    std::vector<Point> hull = convexHull(points);
    // Trouver la distance maximale en utilisant les calipers rotatifs
    double maxDistance = rotatingCalipers(hull);
    // Arrondir la distance maximale à l'entier le plus proche et l'afficher
    std::printf("%.0lf\n", maxDistance);
    return 0;
}
