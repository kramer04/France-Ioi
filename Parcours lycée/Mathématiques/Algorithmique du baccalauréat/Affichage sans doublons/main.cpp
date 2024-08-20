#include <iostream>
#include <cmath>
int main()
{
  int A, N {1};
  std::cin >> A;
  while (N <= std::sqrt(A))
  {
    if (!(A % N))
    {
      if (N != A / N)
        std::cout << N << '\n' << A / N << '\n';
      else
        std::cout << N << '\n';
    }
    N++;
  }
  return 0;
}
