#include <iostream>
#include <string>
#include <cmath>
#include <vector>
void generate(std::vector<std::string> &nom, std::string &letter, std::string mot, int size, int N);
int main()
{
  int L;
  std::cin>> L;
  std::string letters;
  std::cin >> letters;
  int N;
  std::cin >> N;
  std::cout << pow(L, N) << '\n';
  std::vector<std::string> nom;
  generate(nom, letters, "", 0, N);
  
  return 0;
}
void generate(std::vector<std::string> &nom, std::string &letter, std::string mot, int size, int N)
{
  if (size == N)
  {
    std::cout << mot << '\n';
  }
  else
  {
    for (size_t i {0}; i < letter.size(); i++)
      generate(nom, letter, mot + letter [i], size + 1, N);
  }
}
