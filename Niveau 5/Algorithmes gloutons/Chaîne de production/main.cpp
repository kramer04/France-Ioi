#include <iostream>
#include <vector>
#include <algorithm>
int max_f(int count, int max)
{
  return (count > max) ? count : max;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nObjet;
  std::cin >> nObjet;
  int machine;//nombre de machine d'une chaîne
  std::cin >> machine;
  // chaine de production A
  std::cin.tie();
  std::vector<int> m1;
  m1.reserve(machine);
  for (int i {0}; i < machine; i++)
  {
    int a;
    std::cin >> a;
    m1.push_back(a);
  }
  std::vector<int>position(machine, 0), tab1;
  for (int i {0}; i < nObjet; i++)
  {
    int pos {0}, minimum {m1 [pos] + position [pos]};
    for (int j {0}; j < machine; j++)
    {
      if (position [j] + m1 [j] < minimum)
      {
        pos = j;
        minimum = position [j] + m1 [j];
      }
    }
    position [pos] += m1 [pos];
    tab1.push_back(position [pos]);
  }
  std::sort(tab1.begin(), tab1.end());
  std::cout << tab1 [nObjet - 1] << '\n';
  // chaine de production B
  std::cin >> machine;
  std::vector<int> m2;
  m2.reserve(machine);
  position.clear();
  position.resize(machine);
  for (int i {0}; i < machine; i++)
  {
    int a;
    std::cin >> a;
    m2.push_back(a);
  }
  position.clear();
  std::vector<int> tab2;
  for (int i {0}; i < nObjet; i++)
  {
    int pos {0}, minimum {m2 [pos] + position [pos]};
    for (int j {0}; j < machine; j++)
    {
      if (position [j] + m2 [j] < minimum)
      {
        pos = j;
        minimum = position [j] + m2 [j];
      }
    }
    position [pos] += m2 [pos];
    tab2.push_back(position [pos]);
  }
  std::sort(tab2.begin(), tab2.end());
  int max {0};
  for (int i {0}; i < nObjet; i++)
    max = max_f(max, tab1 [i] + tab2 [nObjet - i - 1]);
  std::cout << max << '\n';
    return 0;
}
