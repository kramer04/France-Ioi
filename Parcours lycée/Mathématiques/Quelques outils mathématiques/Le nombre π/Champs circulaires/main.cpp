#include <iostream>
#include <cmath>
int main()
{
  double r {6.0};
  double aire {6 * 6 * M_PI};
  r += 3.0;
  double aireVert {r * r * M_PI - aire};
  double perimetreCloture {2 * 6 * M_PI};
  for (int i {1}; i <= 4; i++)
  {
    r += 3.0;
    aire = r * r * M_PI;
    r += 3;
    aireVert += (r * r * M_PI - aire);
  }
  r = 6.0;
  for (int i {1}; i <= 9; i++)
  {
    r += 3;
    perimetreCloture += 2 * r * M_PI;
  }
  std::cout << static_cast<int>(std::round(aireVert)) << '\n' << static_cast<int>(std::round(perimetreCloture)) << '\n';
  return 0;
}
