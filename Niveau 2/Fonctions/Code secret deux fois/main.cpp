#include <iostream>
#include <string>
void entree()
{
  std::cout << "Entrez le code :" << std::endl;
}
int main()
{
  int code{4242}, psw{0}, nbFois{0};
  while (nbFois != 2)
  {
    if (psw == code)
    {
      nbFois++;
      if (nbFois == 1)
      {
        std::cout << "Encore une fois." << std::endl;
        entree();
        std::cin >> psw;
      }
      else if (nbFois == 2)
      {
        std::cout << "Bravo." << std::endl;
      }
    }
    else
    {
      entree();
      std::cin >> psw;
    }
  }
  return 0;
}
