#include <iostream>
#include <string>
int min2(int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}
int main()
{
  int min{0};
  int entier{0};
  std::cin >> entier;
  min = entier;
  for (int i{2}; i <= 10; i++)
  {
    
    std::cin >> entier;
    min = min2(entier, min);
  }
  std::cout << min << std::endl;
  return 0;
}
