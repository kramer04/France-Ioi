//Attention impossible de soumettre, les tests sont manquants, donc je ne sais pas si ce code passe les tests
//mais il passe l'exemple
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
struct Point {
    int x, y;
};
// Fonction pour trouver l'orientation de l'ordre des points
int orientation(const Point &p, const Point &q, const Point &r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinéaire
    return (val > 0) ? 1 : 2; // 1: horaire, 2: anti-horaire
}
// Fonction pour trouver l'enveloppe convexe des points
std::vector<Point> convexHull(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;
    std::vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }
    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);
    return hull;
}
double calculate_area(const std::vector<Point>& points) {
    int min_x = points[0].x, max_x = points[0].x;
    int min_y = points[0].y, max_y = points[0].y;
    for (const auto& point : points) {
        if (point.x < min_x) min_x = point.x;
        if (point.x > max_x) max_x = point.x;
        if (point.y < min_y) min_y = point.y;
        if (point.y > max_y) max_y = point.y;
    }
    double width = max_x - min_x;
    double height = max_y - min_y;
    return width * height;
}
double minBoundingRectangleArea(std::vector<Point>& hull) {
    double min_area = std::numeric_limits<double>::max();
    int n = hull.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double edge_angle = atan2(hull[j].y - hull[i].y, hull[j].x - hull[i].x);
        double min_x = std::numeric_limits<double>::max(), max_x = std::numeric_limits<double>::lowest();
        double min_y = std::numeric_limits<double>::max(), max_y = std::numeric_limits<double>::lowest();
        for (int k = 0; k < n; k++) {
            double rotated_x = hull[k].x * cos(edge_angle) + hull[k].y * sin(edge_angle);
            double rotated_y = -hull[k].x * sin(edge_angle) + hull[k].y * cos(edge_angle);
            if (rotated_x < min_x) min_x = rotated_x;
            if (rotated_x > max_x) max_x = rotated_x;
            if (rotated_y < min_y) min_y = rotated_y;
            if (rotated_y > max_y) max_y = rotated_y;
        }
        double width = max_x - min_x;
        double height = max_y - min_y;
        double area = width * height;
        if (area < min_area) {
            min_area = area;
        }
    }
    return min_area;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int S;
    std::cin >> S;
    std::vector<Point> points(S);
    for (int i = 0; i < S; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }
    std::vector<Point> hull = convexHull(points);
    double min_area = minBoundingRectangleArea(hull);
    std::cout << std::fixed << std::setprecision(5) << min_area << std::endl;
    return 0;
}

