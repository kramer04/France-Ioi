#include <iostream>
#include <vector>
struct Tmp
{
  int m, n;
};
int f(int n)
{
  return (n > 1) ? n * f(n - 1) : 1;
}
int main()
{
  int n{0};
  std::cin >> n;
  int nb {n};
  std::vector<Tmp> tmp {{0, 0}};
  int i {1}, j {0}, k {1}, n1 {0}, n2 {0};
  while (n1 < n)
  {
    n1 = f(i);
    i++;
  }
  if (n1 > n)
  {
    i -= 2;
    n1 = f(i);
  }
  else
  {
    i--;
    n1 = f(i);
  }
  while (i > 0)
  {
    while (n2 < n)
    {
      j++;
      n2 = n1 * j;
    }
    if (n2 > n)
    {
      j--;
      n2 = n1 * j;
    }
    if (tmp [k - 1].n + n2 <= nb)
    {
      tmp.push_back({j, n2 + tmp [k - 1].n});
      k++;
    }
    else
    {
      tmp.push_back({0, n2 + tmp [k - 1].n});
      k++;
    }
    i--;
    j = 0;
    n -= n2;
    n1 = f(i);
    n2 = 0;
  }
  std::cout << tmp.size() - 1 << "\n";
  for (size_t i {tmp.size() - 1}; i > 0; i--)
    std::cout << tmp [i].m << " ";
  std::cout << std::endl;
}
//2 x 3! + 2 x 2! + 1 x 1! = 12 + 4 + 1 = 17
//
