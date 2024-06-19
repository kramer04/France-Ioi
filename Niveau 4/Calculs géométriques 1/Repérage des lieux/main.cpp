#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
double distance(double ax, double ay, double bx, double by, double px, double py);
int main()
{
  std::ios::sync_with_stdio(false);
  double ax, ay, bx, by;
  std::cin >> ax >> ay >> bx >> by;
  double nblieux;
  std::cin >> nblieux;
  double px, py;
  std::vector<double> pas(nblieux);
  for (double i {0}; i < nblieux; i++)
  {
    std::cin >> px >> py;
    double d = distance(ax, ay, bx, by, px, py);
    pas [i] = d;
  }
  for (double d : pas)
    std::cout << std::fixed << std::setprecision(6) << d << '\n';
  return 0;
}
//H = A + (AP.AB) / ||AB || ^ 2 * AB
double distance(double ax, double ay, double bx, double by, double px, double py)
{
  //coordonnées du vecteur AP
  double xap {px - ax}; //std::cout << "xap = " << xap;
  double yap {py - ay}; //std::cout << " yap = " << yap << '\n';
  //coordonnées du vecteur AB
  double xab {bx - ax}; //std::cout << "xab = " << xab;
  double yab {by - ay}; //std::cout << " yab = " << yab << '\n';
  //produit scalaire de AP.AB
  double scalaire {(xap * xab) + (yap * yab)}; //std::cout << "produit scalaire de AP.AB = " << scalaire << '\n';
  //longueur de AB
  double lab {sqrt(pow(bx - ax, 2) + pow(by - ay, 2))}; //std::cout << "longueur de AB = " << lab << '\n';
  //double lab {bx - ax + by - ay};
  //H = A + (AP . AB) / ||AB||^2 * AB
  //calcul de (AP . AB) / ||AB||^2
  double tmp = scalaire / pow(lab, 2);
  //double tmp = scalaire / lab;
  //calcul de A + (AP . AB) / ||AB||^2 * AB
  double xtmp {tmp * xab}; //std::cout << "xtmp = " << xtmp;
  double ytmp {tmp * yab}; //std::cout << " ytmp = " << ytmp << '\n';
  //coordonnées de H
  double hx = ax + xtmp; //std::cout << "hx = " << hx;
  double hy = ay + ytmp; //std::cout << " hy = " << hy << '\n';
  // distance de A à H, H est la projection orthogonale de P sur la droite AB
  double s {1};
  if (scalaire < 0)
    s = -1;
  double ah = s * sqrt(pow(hx - ax, 2) + pow(hy - ay, 2));
  return ah;
}
