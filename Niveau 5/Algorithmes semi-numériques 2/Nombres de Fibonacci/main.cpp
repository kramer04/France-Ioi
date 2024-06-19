#include <iostream>
/* int fib(int n)
{
  return n <= 1 ? n : fib(n - 2) + fib(n - 1);
} */
unsigned long fibIter(unsigned long n)
{
  unsigned long i, res, f1, f2;
  if (n <= 1)
    res = n;
  else 
{
    f2 = 0;
    f1 = 1;
    for (i = 2; i <= n; i++)
    {
      res = f2 + f1;
      f2 = f1;
      f1 = res;
    }
  }
  return res;
}
int main()
{
  unsigned long N;
  std::cin >> N;
  std::cout << fibIter(N) << '\n';
  return 0;
}
