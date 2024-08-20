#include <iostream>
#include <cmath>

int main()
{
  long long k = 2;
  double threshold = 1e-2;  // 10^-2

  // Boucle jusqu'à ce que ln(k) * k <= 10^-2
  while (std::log(k) / k > threshold)
  {
    ++k;
  }

  std::cout << k << std::endl;

  return 0;
}
//en c++ log(n) est équivalent à ln(n) logarithme népérien.
