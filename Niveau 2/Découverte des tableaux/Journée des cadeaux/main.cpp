#include <iostream>
#include <algorithm>
#include <cmath>
int main()
{
  int nbHabitants{0};
  std::cin >> nbHabitants;
  int fortune [1000] = {0};
  for (int i{0}; i < nbHabitants; i++)
  {
    std::cin >> fortune [i];
  }
  std::sort(fortune, fortune + nbHabitants);
  double median{0};
  if (nbHabitants % 2 == 0)
  {
    median = (double)(fortune [(nbHabitants / 2) - 1] + fortune [nbHabitants / 2]) / 2;
  }
  else
  {
    median = fortune [nbHabitants / 2];
  }
  
  std::cout << median << std::endl;
  return 0;
}
