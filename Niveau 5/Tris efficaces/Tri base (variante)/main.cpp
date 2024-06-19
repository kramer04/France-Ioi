#include <iostream>
#include <vector>
// Fonction pour effectuer le tri par bits
void bitSort(std::vector<int> &arr, int B)
{
  // On va trier de droite à gauche sur B bits
  for (int i = 0; i < B; ++i)
  {
    std::vector<int> zeros, ones;
    // Séparer les nombres en fonction du bit courant (i-th bit)
    for (int num : arr)
    {
      if ((num & (1 << i)) == 0)
      {
        zeros.push_back(num);
      }
      else
      {
        ones.push_back(num);
      }
    }
    // Reconstruire le vecteur dans l'ordre des bits actuels
    arr.clear();
    arr.insert(arr.end(), zeros.begin(), zeros.end());
    arr.insert(arr.end(), ones.begin(), ones.end());
  }
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
  // Nous considérons que les nombres sont codés sur 30 bits (log2(108) + 2 pour une marge de sécurité)
  bitSort(arr, 30);
  for (int i = 0; i < N; ++i)
  {
    std::cout << arr [i] << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
