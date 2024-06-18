#include <iostream>
#include <vector>
struct Amis
{
  int a, b;
};
int main()
{
  std::ios::sync_with_stdio(false);
  int identifiant{0}, nb_relation{0};
  std::cin >> identifiant >> nb_relation;
  std::vector<bool> estami(65000);
  std::vector<Amis> amis;
  for (int i{0}; i < nb_relation; i++)
  {
    int a{0}, b{0};
    std::cin >> a >> b;
    if (a == identifiant)
    {
      estami [b] = true;
    }
    else if (b == identifiant)
    {
      estami [a] = true;
    }
    
    amis.push_back({a, b});
  }
  std::vector<bool> amisDamis(100000);
  int max_amis{0};
  for (size_t i{0}; i < amis.size(); i++)
  {
    if (amis [i].a != identifiant && amis [i].b != identifiant)
    {
      if (estami [amis [i].a] && !estami [amis [i].b])
      {
        amisDamis [amis [i].b] = true;
        if (max_amis < amis [i].b)
          max_amis = amis [i].b;
      }
      else if (!estami [amis [i].a] && estami [amis [i].b])
      {
        amisDamis [amis [i].a] = true;
        if (max_amis < amis [i].a)
          max_amis = amis [i].a;
      }
    }
  }
  int n{0};
  for (int i{0}; i <= max_amis; i++)
  {
    if (amisDamis [i])
      n++;
  }
  std::cout << n << std::endl;
  return 0;
}
