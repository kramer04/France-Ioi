/*
milieu de 2 points (x1,y1) et (x2,y2)
(Xm,Ym) = ((x1+x2)/2,(y1+y2)/2)
*/
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <cmath>
constexpr int N{100};
struct Point
{
  float x, y;
};
int main()
{
  int nbPoints{0};
  std::cin >> nbPoints;
  std::array<std::array<bool, N>, N> grille;
  grille.fill({false});
  std::vector<std::pair<float, float>> point;
  float x{0}, y{0};
  for (int i{0}; i < nbPoints; i++)
  {
    std::cin >> x >> y;
    grille [(int)x][(int)y] = true;
    point.push_back({0,0});
    point [i].first = x;
    point [i].second = y;
  }
  Point milieu;
  int m{0};
  for (int i{0}; i < nbPoints; i++)
  {
    for (int j{i + 1}; j < nbPoints; j++)
    {
      milieu.x = (point [i].first + point [j].first) / 2;
      milieu.y = (point [i].second + point [j].second) / 2;
      if (ceilf(milieu.x) == milieu.x && ceilf(milieu.y) == milieu.y && grille [(int)milieu.x][(int)milieu.y])
      {
        //std::cout << "[" << std::boolalpha << grille [(int)milieu.x][(int)milieu.y] << "]\n["
          //<< milieu.x << ", " << milieu.y << "]" << std::endl;
        grille [(int)milieu.x][(int)milieu.y] = false;
        m++;
      }
    }
  }
  std::cout << m << std::endl;
  return 0;
}
