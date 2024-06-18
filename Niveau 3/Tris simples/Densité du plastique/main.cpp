#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbBacs{0};
  std::cin >> nbBacs;
  std::vector<int> bloc;
  int m;
  for (int i{0}; i < nbBacs; i++)
  {
    std::cin >> m;
    bloc.push_back(m);
  }
  std::sort(bloc.begin(), bloc.end());
  int t{(int)bloc.size() / 2};
  int t1{0};
  if (t % 2 != 0)
    t1++;
  else
    t1 = t;
  int q{0};
  std::cin >> q;
  std::vector<int>::iterator result;
  int question{0};
  for (int i{0}; i < q; i++)
  {
    std::cin >> question;
    //int n{0};
    if (question == bloc [t1])
    {
      std::cout << 1 << '\n';
    }
    else if (question < bloc [t1])
    {
      result = std::find(bloc.begin(), bloc.end() - t1, question);
      (result != bloc.end() - t1) ? std::cout << 1 << '\n' : std::cout << 0 << '\n';
    }
    else
    {
      result = std::find(bloc.begin() + t1, bloc.end(), question);
      (result != bloc.end()) ? std::cout << 1 << '\n' : std::cout << 0 << '\n';
    }
    
    /* result = std::find(bloc.begin(), bloc.end() - t1, question);
    (result != bloc.end() - t1) ? n = 1 : n = 0;
    if (n == 0)
    {
      result = std::find(bloc.begin() + t1, bloc.end(), question);
      (result != bloc.end()) ? n = 1 : n = 0;
      std::cout << n << '\n';
    }
    else
      std::cout << n << '\n'; */
  }
  return 0;
}
