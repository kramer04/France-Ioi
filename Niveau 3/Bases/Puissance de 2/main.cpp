#include <iostream>
#include <cmath>
int main()
{
  int n{0};
  std::cin >> n;
  int i{0};
  while (pow(2,i)<=n)
  {
    i++;
  }
  std::cout.precision(0);
  std::cout << std::fixed << pow(2, i-1) << std::endl;
  return 0;
}
