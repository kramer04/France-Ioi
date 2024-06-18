#include <iostream>
#include <algorithm>
#include <deque>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbAutomobiles{0};
  std::cin >> nbAutomobiles;
  std::deque<int> num;
  for (int i{0}; i < nbAutomobiles; i++)
  {
    num.push_back(0);
    std::cin >> num [i];
  }
  int i{1}, count{0};
  std::ptrdiff_t d{0};
  std::deque<int>::const_iterator it;
  std::deque<int> temp;
  while (i < nbAutomobiles)
  {
    it = std::find(num.cbegin(), num.cend(), i);
    d = std::distance(num.cbegin(), it);
    while (d != i - 1)
    {
      temp.push_back(num [d - 1]);
      temp.push_back(num [d]);
      std::swap(num [d], num [d - 1]);
      it = std::find(num.cbegin(), num.cend(), i);
      d = std::distance(num.cbegin(), it);
      count++;
    }
    i++;
  }
  std::cout << count << "\n";
  for (int i{0}; i < (int)temp.size() - 1; i += 2)
  {
    std::cout << temp [i] << " " << temp [i + 1] << '\n';
  }
  std::cout << "\n";
  return 0;
}
