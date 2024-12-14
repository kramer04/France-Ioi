#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::ios::sync_with_stdio(false);
  int C, R;
  std::cin >> C >> R;
  int N; std::cin >> N;
  std::vector<int> MH(C + 1, 0); // MH[i] = max hauteur objet dans la colonne i (1-based)
  for (int i = 0; i < N; i++)
  {
    int c, r;
    std::cin >> c >> r;
    if (r > MH[c]) MH[c] = r;
  }

  // DP
  const int INF = 1000000000;
  std::vector<int> dp(C + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= C; i++)
  {
    // segment de taille 1 : [i]
    dp[i] = std::min(dp[i], dp[i - 1] + MH[i]);

    // segment de taille 2 : [i-1, i] si possible
    if (i >= 2)
    {
      int m = std::max(MH[i], MH[i - 1]);
      dp[i] = std::min(dp[i], dp[i - 2] + m);
    }

    // segment de taille 3 : [i-2, i-1, i] si possible
    if (i >= 3)
    {
      int m = std::max({MH[i], MH[i - 1], MH[i - 2]});
      dp[i] = std::min(dp[i], dp[i - 3] + m);
    }
  }

  std::cout << dp[C] << '\n';
  return 0;
}

