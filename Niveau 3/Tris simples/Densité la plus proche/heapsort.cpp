// heapsort très rapide
// https://www.geeksforgeeks.org/heap-sort/
#include <iostream>
#include <vector>
using Tab = std::vector<int>;
// C++ program for implementation of Heap Sort
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(Tab &arr, int N, int i)
{
  // Initialize largest as root
  int largest = i;
  // left = 2*i + 1
  int l = 2 * i + 1;
  // right = 2*i + 2
  int r = 2 * i + 2;
  // If left child is larger than root
  if (l < N && arr [l] > arr [largest])
    largest = l;
  // If right child is larger than largest
  // so far
  if (r < N && arr [r] > arr [largest])
    largest = r;
  // If largest is not root
  if (largest != i)
  {
    std::swap(arr [i], arr [largest]);
    // Recursively heapify the affected
    // sub-tree
    heapify(arr, N, largest);
  }
}
// Main function to do heap sort
void heapSort(Tab &arr, int N)
{
  // Build heap (rearrange array)
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);
  // One by one extract an element
  // from heap
  for (int i = N - 1; i > 0; i--)
  {
    // Move current root to end
    std::swap(arr [0], arr [i]);
    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}
// A utility function to print array of size n
void printArray(Tab &arr, int N)
{
  for (int i = 0; i < N; ++i)
    std::cout << arr [i] << " ";
  std::cout << "\n";
}
int binary_search(std::vector<int> &densite, int valeur)
{
  size_t low {0}, high {densite.size() - 1}, mid {0};
  if (valeur <= densite [low])
    return densite [low];
  else if (valeur >= densite [high])
    return densite [high];
  else if (valeur == densite [(low + high) / 2])
    return densite [(low + high) / 2];
  while (low <= high)
  {
    if (low == high)
      return densite [low];
    if (low + 1 == high)
    {
      if (valeur - densite [low] <= densite [high] - valeur)
        return densite [low];
      else
        return densite [high];
    }
    mid = (low + high) / 2;
    (valeur <= densite [mid]) ? high = mid : low = mid;
  }
  return -1;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int nbValeurs;
  std::cin >> nbValeurs;
  std::vector<int> densite(nbValeurs);
  for (int i {0}; i < nbValeurs; i++)
    std::cin >> densite [i];
  heapSort(densite, nbValeurs);
  //std::sort(densite.begin(), densite.end());
  int question, cible;
  std::cin >> question;
  //std::cout << '\n';
  for (int i {0}; i < question; i++)
  {
    std::cin >> cible;
    int m {binary_search(densite, cible)};
    std::cout << m << '\n';
  }
  return 0;
}
