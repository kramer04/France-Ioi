#include <iostream>
#include <map>
int max_f(int count, int max)
{
  return (count > max) ? count : max;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nb;
  std::cin >> nb;
  std::map<int, int>musique;
  int n, max {0};
  for (int i {0}; i < nb; i++)
  {
    std::cin >> n;
    if (n)
      musique [n]++;
    else
    {
      max = max_f(musique.size(), max);
      musique.clear();
    }
  }
  max = max_f(musique.size(), max);
  std::cout << max << '\n';
  return 0;
}
