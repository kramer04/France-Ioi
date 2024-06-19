#include <iostream>
#include <vector>
// Fonction pour séparer et trier les nombres en fonction du bit de poids fort
void bitSort(std::vector<int> &arr, int bit)
{
  if (bit < 0 || arr.size() <= 1)
  {
    return;
  }
  std::vector<int> zeros, ones;
  // Séparer les nombres en fonction du bit courant
  for (int num : arr)
  {
    if ((num & (1 << bit)) == 0)
    {
      zeros.push_back(num);
    }
    else
    {
      ones.push_back(num);
    }
  }
  // Tri récursif des deux sous-groupes
  bitSort(zeros, bit - 1);
  bitSort(ones, bit - 1);
  // Fusionner les résultats
  arr.clear();
  arr.insert(arr.end(), zeros.begin(), zeros.end());
  arr.insert(arr.end(), ones.begin(), ones.end());
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; ++i)
  {
    std::cin >> arr [i];
  }
  // Nous considérons que les nombres sont codés sur 27 bits (log2(108) ≈ 27)
  bitSort(arr, 27);
  for (int i = 0; i < N; ++i)
  {
    std::cout << arr [i] << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
