#include <iostream>
#include <algorithm>
#include <vector>
struct Representation
{
  int debut, fin, salle;
  bool operator<(Representation const &i)const
  {
    return debut < i.debut;
  }
};
bool tri(std::vector<Representation> &r, std::vector<int> &p, std::vector<int> &local, int s, int rp);
int main()
{
  std::ios_base::sync_with_stdio(0);
  int salle, rp;
  std::cin >> salle >> rp;
  
  std::vector<Representation> rep(rp);
  std::vector<int>local(rp);
  std::vector<int>piece(salle, -1);
  
  for (int i {0}; i < rp; i++)
  {
    std::cin >> rep [i].debut >> rep [i].fin;
    rep [i].salle = i;
  }
  std::sort(rep.begin(), rep.end());
  if (tri(rep, piece, local, salle, rp))
  {
    std::cout << "OUI" << '\n';
    for (int i = 0; i < rp; i++)
      std::cout << local [i] << " ";
    std::cout << '\n';
  }
  else
    std::cout << "NON" << '\n';
  return 0;
}
bool tri(std::vector<Representation> &r, std::vector<int> &p, std::vector<int> &local, int s, int rp)
{
  int i {0};
  for (; i < rp; i++)
  {
    int j {0};
    for (; j < s; j++)
    {
      if (r [i].debut >= p [j])
      {
        p [j] = r [i].fin;
        local [r [i].salle] = j + 1;
        break;
      }
    }
    if (j == s)
      return false;
  }
  return true;
}
