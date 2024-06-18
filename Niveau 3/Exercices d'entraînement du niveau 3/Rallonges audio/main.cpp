#include <iostream>
#include <algorithm>
#include <vector>
struct Rallonge
{
  int b1, b2;
  int longueur, type;
};
using Cable = std::vector<Rallonge>;
int main()
{
  int b1, b2;
  int nb_cable{0}, l{0}, type_rallonge{0}, nb_rallonge_00{0}, nb_rallonge_11{0}, nb_rallonge_01{0};// 0=0-0 1=1-1 2=0-1||1-0
  Cable cable;
  std::cin >> nb_cable;
  for (int i{0}; i < nb_cable; ++i)
  {
    std::cin >> b1 >> b2 >> l;
    if (b1 == 0 && b2 == 0)
    {
      type_rallonge = 0;
      nb_rallonge_00++;
    }
    else if (b1 == 1 && b2 == 1)
    {
      type_rallonge = 1;
      nb_rallonge_11++;
    }
    else
    {
      type_rallonge = 2;
      nb_rallonge_01++;
    }
    cable.push_back({b1, b2, l, type_rallonge});
  }
  //std::sort(cable.begin(), cable.end(), [](Rallonge &lhs, Rallonge &rhs) {return lhs.longueur > rhs.longueur; });
  int count{0};
  if (nb_rallonge_11 == 0)
    std::cout << -1 << std::endl;
  else if (nb_rallonge_00 > 0 && (nb_rallonge_11 - nb_rallonge_00) > 1)
  {
    size_t i{0}, j{0}, t{cable.size()};
    int min{100001}, tmp{nb_rallonge_11};
    while (i < t)
    {
      if (nb_rallonge_11 - nb_rallonge_00 > 1)
      {
        for (size_t k{0}; k < t; ++k)
        {
          if (cable [k].type == 1 && min > cable [k].longueur)
          {
            min = cable [k].longueur;
            j = k;
          }
        }
        nb_rallonge_11--;
        cable.erase(cable.begin() + j);
        t = cable.size();
        min = 100001;
        i--;
      }
      i++;
    }
    for (auto d : cable)
      count += d.longueur;
    
    std::cout << count << std::endl;
    count = 0;
    nb_rallonge_11 = tmp;
  }
  else if (nb_rallonge_00 - nb_rallonge_11 >= 0)
  {
    size_t i{0}, j{0}, t{cable.size()};
    int min{100001}, tmp{nb_rallonge_00};
    while (i < t)
    {
      if (nb_rallonge_00 - nb_rallonge_11 >= 0)
      {
        for (size_t k{0}; k < t; ++k)
        {
          if (cable [k].type == 0 && min > cable [k].longueur)
          {
            min = cable [k].longueur;
            j = k;
          }
        }
        nb_rallonge_00--;
        cable.erase(cable.begin() + j);
        t = cable.size();
        min = 100001;
        i--;
      }
      i++;
    }
    for (auto d : cable)
      count += d.longueur;
    std::cout << count << std::endl;
    count = 0;
    nb_rallonge_00 = tmp;
  }
  else if (nb_rallonge_00 == 0 && nb_rallonge_01 == 0 && nb_rallonge_11 > 0)
  {
    int max{0};
    for (size_t i{0}; i < cable.size(); ++i)
    {
      if (cable[i].type == 1 && max < cable [i].longueur)
        max = cable [i].longueur;
    }
    std::cout << max << std::endl;
  }
  else if (nb_rallonge_00 == 0 && (nb_rallonge_01 - nb_rallonge_11) >= 0)
  {
    size_t i{0}, j{0}, t{cable.size()};
    int min{100001}, tmp{nb_rallonge_11};
    while (i < t)
    {
      if (cable[i].type == 1 && nb_rallonge_11 > 1)
      {
        for (size_t k{0}; k < t; ++k)
        {
          if (cable [k].type == 1 && min > cable [k].longueur)
          {
            min = cable [k].longueur;
            j = k;
          }
        }
        nb_rallonge_11--;
        cable.erase(cable.begin() + j);
        t = cable.size();
        min = 100001;
        i--;
      }
      i++;
    }
    for (auto d : cable)
      count += d.longueur;
    std::cout << count << std::endl;
    count = 0;
    nb_rallonge_11 = tmp;
  }
  else
  {
    for (auto d : cable)
      count += d.longueur;
    std::cout << count << std::endl;
  }
  return 0;
}
