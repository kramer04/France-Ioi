#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//constexpr int N{64};
using Grille = std::vector<std::vector<std::string>>;
void sierpinski(Grille &t64, size_t n, size_t N);
void rtrim(std::string &s);
int main()
{
  size_t N;
  std::cin >> N;
  Grille t;
  for (size_t i{0}; i < N; i++)
  {
    t.push_back(std::vector<std::string>(N));
    for (size_t j{0}; j < N; j++)
    {
      t [i][j] = ' ';
    }
  }
  t [0][0] = '#'; //t [0][1] = '#'; t [1][0] = '#';
  sierpinski(t, 2, N);
  for (size_t i{0}; i < t.size(); i++)
  {
    for (size_t j{0}; j < t.size()-i; j++)
    {
      //rtrim(t [i][j]);
      std::cout << t [i][j];
    }
    std::cout << "\n";
  }
  return 0;
}
// trim from end (in place)
void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {return !std::isspace(ch); }).base(), s.end());
}
void sierpinski(Grille &t64, size_t n, size_t N)
{
  if (n == N*2)
    return;
  
  for (size_t i{0}; i < n / 2 ; i++)
  {
    for (size_t j{0}; j < n / 2 ; j++)
    {
      t64 [i + n / 2][j] = t64 [i][j];
      t64 [i][j + n / 2] = t64 [i][j];
    }
  }
  sierpinski(t64, n * 2, N);
}
