#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <array>
constexpr std::array<std::array<int, 2>, 4> dir
{
  0, 1,
  -1, 0,
  0, -1,
  1, 0
};
const char D [4] = {'E', 'N', 'O', 'S'};
int L, C;
std::vector<std::string> maze;
std::vector<std::vector<int>> dist;
std::vector<std::vector<int>> pre;
bool is_valid(int x, int y)
{
  return x >= 0 && x < L && y >= 0 && y < C && maze [x][y] == '.';
}
void bfs()
{
  std::queue<std::pair<int, int>> q;
  q.push({1, 0});
  dist [1][0] = 0;
  while (!q.empty())
  {
    std::pair<int, int> u = q.front();
    q.pop();
    for (int i {0}; i < 4; i++)
    {
      int x {u.first + dir [i][0]}, y {u.second + dir [i][1]};
      if (is_valid(x, y) && dist [x][y] == -1)
      {
        q.push({x, y});
        dist [x][y] = dist [u.first][u.second] + 1;
        pre [x][y] = i;
      }
    }
  }
}
int main()
{
  std::cin >> L >> C;
  maze.resize(L);
  dist.resize(L, std::vector<int>(C, -1));
  pre.resize(L, std::vector<int>(C));
  for (int i {0}; i < L; i++)
    std::cin >> maze [i];
  bfs();
  int x {L - 1};
  int y {C - 2};
  int d {dist [x][y]};
  std::string ans = "";
  while (x != 1 || y != 0)
  {
    int k {pre [x][y]};
    ans = D [k] + ans;
    x -= dir [k][0];
    y -= dir [k][1];
  }
  std::cout << d << '\n';
  std::cout << ans << '\n';
  return 0;
}
