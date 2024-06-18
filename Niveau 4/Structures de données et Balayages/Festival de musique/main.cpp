#include <iostream>
#include <unordered_map>
#include <climits>
int nbJours, nbGroupes;
int minSequence = INT_MAX;
int groupes [100005];
std::unordered_map<int, int> lastSeen;
int main()
{
  std::cin >> nbJours >> nbGroupes;
  for (int i {1}; i <= nbJours; i++)
    std::cin >> groupes [i];
  int debut {1}, fin {1}, groupesVus {0};
  while (fin <= nbJours)
  {
    if (lastSeen [groupes [fin]] < debut)
    {
      groupesVus++;
    }
    lastSeen [groupes [fin]] = fin;
    while (groupesVus == nbGroupes)
    {
      minSequence = std::min(minSequence, fin - debut + 1);
      if (lastSeen [groupes [debut]] == debut) groupesVus--;
      debut++;
    }
    fin++;
  }
  std::cout << minSequence << '\n';
  return 0;
}
