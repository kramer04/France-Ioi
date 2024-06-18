#include <iostream>
#include <string>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  std::string ligne{}, mot{};
  int n{0};
  std::cin >> n;
  for (int i{0}; i < n; i++)
  {
    std::cin >> ligne;
    auto it = std::find(ligne.begin(), ligne.end(), 'O');
    while (it != ligne.end())
    {
      auto d = std::distance(ligne.begin(), it);
      mot += d + 'A';
      
      it = std::find(ligne.begin() + d + 1, ligne.end(), 'O');
    }
  }
  std::cout << mot << std::endl;
  
  return 0;
}
