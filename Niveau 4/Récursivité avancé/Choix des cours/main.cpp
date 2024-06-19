#include <iostream>
#include <vector>
void swap(int &a, int &b);
void permute(std::vector<int> &sortie, int n, int k, int start);
int main()
{
  std::ios_base::sync_with_stdio(0);
  int N, K;
  std::cin >> N >> K;
  std::vector<int>sortie;
  if (N == K)
    for (int i {1}; i <= N; i++)
      std::cout << i << " ";
  else if (K > N)
    std::cout << "" << '\n';
  else
    permute(sortie, N, K, 1);
}
void swap(int &a, int &b)
{
  int tmp {a};
  a = b;
  b = tmp;
}
void permute(std::vector<int> &sortie, int n, int k, int start)
{
  if ((int) sortie.size() == k)
  {
    for (int i : sortie)
      std::cout << i << " ";
    std::cout << '\n';
  }
  else if (n - start + 1 < k - (int) sortie.size())
    return;
  else
  {
    for (int i {start}; i <= n; i++)
    {
      sortie.push_back(i);
      swap(start, i);
      permute(sortie, n, k, start + 1);
      swap(start, i);
      sortie.pop_back();
    }
  }
}
//nombre de k-uplets d’éléments distincts dans un ensemble E
//n(n – 1) × … ×(n – k + 1) = n! / (n - k)!
