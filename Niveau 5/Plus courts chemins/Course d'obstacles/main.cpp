// algorithm de dijkstra
//code 1
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <climits>
struct Cell
{
  int x, y, cost;
  bool operator>(const Cell &other) const
  {
    return cost > other.cost;
  }
};
bool is_valid(int x, int y, int l, int c)
{
  return x >= 0 && x < l && y >= 0 && y < c;
}
int dijkstra(const std::vector<std::vector<char>> &lab, int l, int c)
{
  std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> pq;
  std::vector<std::vector<int>> dist(l, std::vector<int>(c, INT_MAX));
  pq.push({1, 0, 0});
  dist [1][0] = 0;
  const std::array<int, 4> dx {-1, 1, 0, 0};
  const std::array<int, 4> dy {0, 0, -1, 1};
  while (!pq.empty())
  {
    Cell current = pq.top();
    pq.pop();
    int x {current.x};
    int y {current.y};
    int cost = current.cost;
    if (x == l - 1 && y == c - 2)
    {
      return cost;
    }
    for (int i {0}; i < 4; ++i)
    {
      int nx = x + dx [i];
      int ny = y + dy [i];
      if (is_valid(nx, ny, l, c) && lab [nx][ny] != '#')
      {
        int next_cost = cost + (lab [nx][ny] == '.' ? 0 : lab [nx][ny] - '0');
        if (next_cost < dist [nx][ny])
        {
          dist [nx][ny] = next_cost;
          pq.push({nx, ny, next_cost});
        }
      }
    }
  }
  return -1;  // Si la sortie n'est pas atteignable
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int l, c;
  std::cin >> l >> c;
  std::vector<std::vector<char>> lab(l, std::vector<char>(c));
  for (int i {0}; i < l; ++i)
  {
    for (int j {0}; j < c; ++j)
    {
      std::cin >> lab [i][j];
    }
  }
  int result = dijkstra(lab, l, c);
  std::cout << result << std::endl;
  return 0;
}
