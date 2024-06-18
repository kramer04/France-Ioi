#include <iostream>
#include <algorithm>
#include <deque>
int main()
{
  std::ios::sync_with_stdio(false);
  int N_bacs{0}, M_inserer;
  std::cin >> N_bacs >> M_inserer;
  std::deque<int> pollution;
  for (int i{0}; i < N_bacs; i++)
  {
    pollution.push_back(0);
    std::cin >> pollution [i];
  }
  std::deque<int> bac_en_plus;
  for (int i{0}; i < M_inserer; i++)
  {
    bac_en_plus.push_back(0);
    std::cin >> bac_en_plus [i];
  }
  for (int i{0}; i < (int)bac_en_plus.size(); i++)
  {
    pollution.push_back(bac_en_plus [i]);
    std::sort(std::begin(pollution), std::end(pollution)); //, [](const int p, const int p1) {return p < p1; });
    auto it = std::find(pollution.cbegin(), pollution.cend(), bac_en_plus [i]);
    std::cout << std::distance(pollution.cbegin(), it) << " ";
  }
  //auto m = [](const int &n) {std::cout << n - 1 << " "; };
  //std::for_each(bac_en_plus.cbegin(), bac_en_plus.cend(), m);
  std::cout << '\n';
  
  for (int i{0}; i < (int)pollution.size(); i++)
  {
    std::cout << pollution [i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
