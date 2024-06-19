// tri par tas (heap) en utilisant la bibliothèque standard (heap)
// code 2
#include <iostream>
#include <queue>
#include <vector>
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Utilisation d'un tas min
  // Lecture des N entiers
  for (int i = 0; i < N; ++i)
  {
    int value;
    std::cin >> value;
    minHeap.push(value); // Insérer dans le tas
  }
  // Extraction des éléments triés
  std::vector<int> sortedArray;
  while (!minHeap.empty())
  {
    sortedArray.push_back(minHeap.top());
    minHeap.pop();
  }
  // Affichage du résultat
  for (int i = 0; i < N; ++i)
  {
    std::cout << sortedArray [i];
    if (i < N - 1) std::cout << " ";
  }
  std::cout << '\n';
  return 0;
}
