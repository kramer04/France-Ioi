#include <iostream>
#include <string>
#include <cmath>
#include <vector>
uint64_t fact(int n);
void generate(std::vector<bool> &vu, std::vector<std::string> &nom, std::string &letter, std::string mot, int size, int N);
int main()
{
  std::ios_base::sync_with_stdio(0);
  int L;
  std::cin >> L;
  std::string letters;
  std::cin >> letters;
  int N;
  std::cin >> N;

  if (N > L)
  {
    std::cout << 0 << '\n';
    return 0;
  }
  else
  {
    uint64_t a {fact(L)}, b {fact(L - N)};
    std::cout << a / b << '\n';
  }
  std::vector<bool> vu(26, false);
  std::vector<std::string> nom;
  generate(vu, nom, letters, "", 0, N);
  for (size_t i {0}; i < nom.size(); i++)
    std::cout << nom [i] << '\n';

  return 0;
}
uint64_t fact(int n)
{
  return n > 1 ? n * fact(n - 1) : 1;
}
void generate(std::vector<bool> &vu, std::vector<std::string> &nom, std::string &letter, std::string mot, int size, int N)
{
  if (size == N)
  {
    nom.push_back(mot);

  }
  else
  {
    for (size_t i {0}; i < letter.size(); i++)
    {
      if (!vu [i])
      {
        vu [i] = true;
        generate(vu, nom, letter, mot + letter [i], size + 1, N);
        vu [i] = false;
      }
    }
  }
}
