#include <iostream>
int main()
{
  int eleves, salles;
  std::cin >> eleves >> salles;
  int reservation {salles / eleves};
  
  if ((salles % eleves) != 0)
    std::cout << reservation + 1 << '\n';
  else
    std::cout << reservation << '\n';
}
