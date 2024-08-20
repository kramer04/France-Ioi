#include <iostream>

int main()
{
  int sommeActuelle, beneficeMensuel, nombreMois;
  std::cin >> sommeActuelle >> beneficeMensuel >> nombreMois;

  for (int i {0}; i < nombreMois; ++i)
  {
    std::cout << sommeActuelle << '\n';
    sommeActuelle += beneficeMensuel;
  }
  return 0;
}
