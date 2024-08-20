//Suite de Fibonacci sans la citer dans l'exercice

#include <iostream>
int fib(int n)
{
  return n <= 1 ? n : fib(n - 2) + fib(n - 1);
}
int main()
{
  int nbTour;
  std::cin >> nbTour;
  for (int i {1}; i <= nbTour; ++i)
  {
    std::cout << fib(i) << '\n';
  }
  return 0;
}
