#include <iostream>
#include <queue>
#include <vector>
#include <array>
constexpr int N {1010};
constexpr std::array<std::array<int, 2>, 4> dir
{
  -1, 0,
  0, 1,
  1, 0,
  0, -1
};
int n, m, k;
char a [N][N];
bool st [N][N];
int d [N][N];
std::queue<std::pair<int, int>> q;
bool dansPlateau(int lin, int col, int l, int c);
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i {0}; i < n; i++)
    for (int j {0}; j < m; j++)
      std::cin >> a [i][j];
  std::cin >> k;
  q.push({n - 1, m - 2});
  st [n - 1][m - 2] = true;
  while (!q.empty())
  {
    int x {q.front().first}, y {q.front().second};
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx {x + dir [i][0]}, ny {y + dir [i][1]};
      if (dansPlateau(nx,ny,n,m) && !st [nx][ny] && a [nx][ny] == '.')
      {
        q.push({nx, ny});
        st [nx][ny] = true;
        d [nx][ny] = d [x][y] + 1;
      }
    }
  }
  std::vector<int> cnt(k + 1, 0);
  for (int i {0}; i < n; i++)
  {
    for (int j {0}; j < m; j++)
    {
      if (d [i][j] <= k)
        cnt [d [i][j]]++;
    }
  }
  for (int i {1}; i <= k; i++)
    std::cout << cnt [i] << ' ';
  std::cout << '\n';
  return 0;
}
bool dansPlateau(int lin, int col, int l, int c)
{
  return ((lin >= 0) && (lin < l) && (col >= 0) && (col < c));
}
