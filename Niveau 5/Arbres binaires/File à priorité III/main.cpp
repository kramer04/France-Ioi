#include <iostream>
#include <queue>
#include <vector>
#include <functional>
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int R;
  std::cin >> R;
  // Utilisation d'un priority_queue avec un comparateur pour faire un min-heap
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  for (int i = 0; i < R; ++i)
  {
    char query;
    std::cin >> query;
    if (query == 'I')
    {
      int value;
      std::cin >> value;
      minHeap.push(value);
    }
    else if (query == 'E')
    {
      if (minHeap.empty())
      {
        std::cout << "-" << std::endl;
      }
      else
      {
        std::cout << minHeap.top() << std::endl;
        minHeap.pop();
      }
    }
  }
  return 0;
}
