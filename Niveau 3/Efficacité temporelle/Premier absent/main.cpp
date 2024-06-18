#include <iostream>
#include <set>
int main()
{
  std::ios::sync_with_stdio(false);
  int n{0}, p{0}, absent{1}; //N est le nombre d'élèves inscrits dans votre classe. P est le nombre d'élèves présents aujourd'hui.
  std::cin >> n >> p;
  int e{0}; // E élèves allant en cours
  std::set<int> enClasse;
  for (int i{1}; i <= p; ++i)
  {
    std::cin >> e;
    enClasse.insert(e);
    if (i == n)
      std::cout << -1 << std::endl;
    else
    {
      if (absent == e)
      {
        for (auto it = enClasse.begin(); it != enClasse.end(); ++it)
        {
          if (absent != *it)
            break;
          enClasse.erase(absent);
          absent++;
        }
      }
      std::cout << absent << std::endl;
    }
    
  }
  return 0;
}
