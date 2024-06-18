#include <iostream>
int main()
{
  int nbCubes{0};
  std::cin >> nbCubes;
  int i{1}, base{1}, nbC{0}, hauteur{0};
  while ((i * i + nbC) <= nbCubes)
  {
    base = i * i;
    nbC = nbC + base;
    hauteur++;
    i++;
  }
  std::cout << hauteur << std::endl;
  std::cout << nbC << std::endl;
  return 0;
}
