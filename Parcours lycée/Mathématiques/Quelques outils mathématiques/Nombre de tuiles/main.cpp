#include <cmath>
#include <iostream>
#include <iomanip>
int main()
{
  double F, L, H, h;
  std::cin >> F >> L >> H >> h;
  H = H - h;
  F = F / 2;
  double c; //hypothénuse
  c = std::sqrt(H * H + F * F);
  double aire_toit {0.0};
  aire_toit = (c * L) * 2;
  std::cout << std::fixed << std::showpoint << std::setprecision(1) << aire_toit << std::endl;
  return 0;
}
