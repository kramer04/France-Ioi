#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  int l, h, nbMurs;
  std::cin >> l >> h >> nbMurs;
  std::vector<std::pair<int, int>> mur;
  for (int i {0}; i < nbMurs; i++)
  {
    int ax, by, cx, dy;
    std::cin >> ax >> by >> cx >> dy;
    mur.push_back({ax, by - dy});
    mur.push_back({cx, dy - by});
  }
/*     for (int i {0}; i < (int) mur.size(); i++)
      std::cout << mur [i].first << " " << mur [i].second << '\n';
    std::sort(mur.begin(), mur.end()); */
/*     std::cout << "-----------------\n";
    for (int i {0}; i < (int)mur.size(); i++)
      std::cout << mur [i].first << " " << mur [i].second << '\n'; */
  std::sort(mur.begin(), mur.end());
  if (mur [0].first > 0 || mur [mur.size() - 1].first < l)
    std::cout << 0 << '\n';
  else
  {
    int somme {-mur [0].second};
    int min {INT32_MAX};//2147483647 = 0x7fffffff
    //std::cout << min << '\n';
    for (int i {1}; i < nbMurs * 2; i++)
    {
      if (min > somme && mur [i].first != mur [i - 1].first)
      {
        min = somme; //std::cout << "min = " << min << '\n';
      }
      somme -= mur [i].second; //std::cout << "somme = " << somme << '\n';
    }
    std::cout << min << '\n';
  }
  return 0;
}
