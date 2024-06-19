#include <vector>
#include <iostream>
struct SegmentTree
{
  std::vector<int> tree;
  int n;
  SegmentTree(const std::vector<int> &arr)
  {
    n = arr.size();
    tree.resize(2 * n);
    build(arr);
  }
  void build(const std::vector<int> &arr)
  {
    for (int i = 0; i < n; ++i)
    {
      tree [n + i] = arr [i];
    }
    for (int i = n - 1; i > 0; --i)
    {
      tree [i] = tree [i * 2] + tree [i * 2 + 1];
    }
  }
  void update(int pos, int value)
  {
    pos += n;  // Se déplacer vers la feuille correspondante
    tree [pos] = value;  // Mettre à jour la valeur de la feuille
    while (pos > 1)
    {  // Remonter l'arbre pour mettre à jour les nœuds parents
      pos /= 2;
      tree [pos] = tree [2 * pos] + tree [2 * pos + 1];
    }
  }
  int query(int l, int r)
  {
    l += n;
    r += n;
    int sum = 0;
    while (l <= r)
    {
      if (l % 2 == 1)
      {
        sum += tree [l];
        l++;
      }
      if (r % 2 == 0)
      {
        sum += tree [r];
        r--;
      }
      l /= 2;
      r /= 2;
    }
    return sum;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  int taille;
  std::cin >> taille;
  std::vector<int> arr(taille);
  for (int i {0}; i < taille; i++)
    std::cin >> arr [i];
  int nbRequetes;
  std::cin >> nbRequetes;
  SegmentTree st(arr);
  char c;
  for (int i {0}; i < nbRequetes; i++)
  {
    std::cin >> c;
    int a, b;
    if (c == 'M')
    {
      std::cin >> a >> b;
      st.update(a, b);
    }
    else
    {
      std::cin >> a >> b;
      std::cout << st.query(a, b) << "\n";
    }
  }
  return 0;
}
