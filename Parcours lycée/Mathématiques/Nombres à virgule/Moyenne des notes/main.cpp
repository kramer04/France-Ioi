#include <iostream>
int main()
{
  int nbNotes{0}, notes{0}, moyenne{0};
  std::cin >> nbNotes;
  for (int i{1}; i <= nbNotes; i++)
  {
    std::cin >> notes;
    moyenne += notes;
  }
  std::cout << (double)moyenne / nbNotes << std::endl;
  return 0;
}
