//https://www.france-ioi.org/algo/task.php?idChapter=532&idTask=755
#include<iostream>
#include <vector>
#include <algorithm>
struct Evenement
{
  int position;
  int delta; // +1 pour un début de segment, -1 pour une fin
  Evenement(int p = 0, int d = 0) : position(p), delta(d) {}
};
/* bool compare(const Evenement &evtA, const Evenement &evtB)
{
  if (evtA.position == evtB.position)
  {
    return evtA.delta < evtB.delta;
  }
  return evtA.position < evtB.position;
} */
auto compare = [](Evenement const &evt1, Evenement const &evt2) {
  if (evt1.position == evt2.position)
  {
    return evt1.delta < evt2.delta;
  }
  return evt1.position < evt2.position; };
/* struct
{
  bool operator()(Evenement const &evt1, Evenement const &evt2)
  {
    if (evt1.position == evt2.position)
    {
      return evt1.delta < evt2.delta;
    }
    return evt1.position < evt2.position;
  }
}compare; */
int main()
{
  std::ios_base::sync_with_stdio(0);
  int nbGuide, nbTouriste;
  std::cin >> nbGuide >> nbTouriste;
  std::vector<Evenement> evenements;
  for (int i {0}; i < nbTouriste; i++)
  {
    int debut, fin;
    std::cin >> debut >> fin;
    evenements.push_back(Evenement(debut, 1));
    evenements.push_back(Evenement(fin, -1));
  }
  std::sort(evenements.begin(), evenements.end(), compare); //ne fonctionne pas avec list
  int total = 1;
  int nbOuverts = 0;
  for (auto evt = evenements.begin(); evt != evenements.end(); evt++)
  {
    nbOuverts += evt->delta;
    if (nbOuverts > nbGuide)
    {
      total = 0;
      //  total += std::next(evt)->position - evt->position;
    }
  }
  std::cout << total << std::endl;
}
