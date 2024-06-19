#include <iostream>
#include <stdexcept>
#include <iomanip>
struct Point
{
  double x, y;
};
// Fonction pour calculer l'intersection du point des droites
Point intersection(Point p1, Point p2, Point p3, Point p4)
{
  // Calcule les coefficients
  double A1 = p2.y - p1.y;
  double B1 = p1.x - p2.x;
  double C1 = A1 * p1.x + B1 * p1.y;
  double A2 = p4.y - p3.y;
  double B2 = p3.x - p4.x;
  double C2 = A2 * p3.x + B2 * p3.y;
  // Calcule le determinant
  double determinant = A1 * B2 - A2 * B1;
  // Calcule l'intersection du point
  Point intersect;
  intersect.x = (B2 * C1 - B1 * C2) / determinant;
  intersect.y = (A1 * C2 - A2 * C1) / determinant;
  return intersect;
}
int main()
{
  Point p1, p2, p3, p4;
  std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
  std::cin >> p3.x >> p3.y >> p4.x >> p4.y;
  
  Point intersect = intersection(p1, p2, p3, p4);
  std::cout << std::setprecision(6) << std::fixed << intersect.x << " " << intersect.y << "\n";
  return 0;
}
