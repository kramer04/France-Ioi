#include <iostream>
#include <algorithm>
int main()
{
  int nbParticipants{0};
  std::cin >> nbParticipants;
  int choix [3000] = {0};
  for (int i{0}; i < nbParticipants; i++)
  {
    std::cin >> choix [i];
  }
  std::sort(choix, choix + nbParticipants);
  for (int i{0}; i < nbParticipants / 2; i++)
  {
    std::cout << choix [i] << " " << choix [nbParticipants - i - 1] << std::endl;
  }
  return 0;
}
