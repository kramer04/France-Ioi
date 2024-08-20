
#include <iostream>
int main()
{
  int nombre;
  std::cin >> nombre;
  int reste {0};
  if (nombre == 2)
    std::cout << "Premier\n";
  else
    for (int i {2}; i < nombre; ++i)
    {
      reste = nombre % i;
      if (!reste)
      {
        std::cout << "Composé\n";
        break;
      }
      else if (reste && i == nombre - 1)
        std::cout << "Premier\n";
    }
  return 0;
}
