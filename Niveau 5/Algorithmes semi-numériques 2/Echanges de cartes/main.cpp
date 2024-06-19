//code 3
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int N;
  std::cin >> N;
  std::vector<int> cards(N);
  for (int i = 0; i < N; ++i)
  {
    std::cin >> cards [i];
  }
  std::vector<std::pair<int, int>> swaps;
  for (int i = 0; i < N - 1; ++i)
  {
    int minIndex = i;
    for (int j = i + 1; j < N; ++j)
    {
      if (cards [j] < cards [minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      std::swap(cards [i], cards [minIndex]);
      swaps.push_back({i + 1, minIndex + 1});
    }
  }
  std::cout << swaps.size() << '\n';
  for (const auto &s : swaps)
  {
    std::cout << s.first << " " << s.second << '\n';
  }
  return 0;
}
