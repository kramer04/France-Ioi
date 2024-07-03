#include <iostream>
#include <vector>
#include <tuple>
// Structure pour représenter un point
struct Point {
    int x, y;
};
// Structure pour représenter un segment
struct Segment {
    Point p1, p2;
};
// Fonction pour déterminer l'orientation de l'ordre triplet (p, q, r)
// 0 --> p, q et r sont colinéaires
// 1 --> Sens horaire
// 2 --> Sens anti-horaire
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinéaire
    return (val > 0) ? 1 : 2; // horaire ou anti-horaire
}
// Fonction pour vérifier si q se situe sur le segment pr
bool onSegment(Point p, Point q, Point r) {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y);
}
// Fonction pour vérifier si deux segments se croisent
bool segmentsIntersect(Segment s1, Segment s2) {
    Point p1 = s1.p1, q1 = s1.p2;
    Point p2 = s2.p1, q2 = s2.p2;
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    // Cas général
    if (o1 != o2 && o3 != o4)
        return true;
    // Cas particuliers
    if (o1 == 0 && onSegment(p1, p2, q1)) return false;
    if (o2 == 0 && onSegment(p1, q2, q1)) return false;
    if (o3 == 0 && onSegment(p2, p1, q2)) return false;
    if (o4 == 0 && onSegment(p2, q1, q2)) return false;
    return false; // Ne se croisent pas
}
int main() {
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
    // Lecture du nouveau segment
    Segment newSegment;
    std::cin >> newSegment.p1.x >> newSegment.p1.y >> newSegment.p2.x >> newSegment.p2.y;
    // Lecture du nombre de segments existants
    int N;
    std::cin >> N;
    // Lecture des segments existants
    std::vector<Segment> existingSegments(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> existingSegments[i].p1.x >> existingSegments[i].p1.y >> existingSegments[i].p2.x >> existingSegments[i].p2.y;
    }
    // Analyse des intersections
    for (const auto& segment : existingSegments) {
        if (segmentsIntersect(newSegment, segment)) {
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }
    return 0;
}
