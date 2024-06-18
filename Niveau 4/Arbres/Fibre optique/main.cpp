#include <iostream>
#include <vector>
using Vector = std::vector<std::vector<int>>;
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
template <typename T>
T min_f(T count, T max)
{
  return (count < max) ? count : max;
}
void dfs(int node, int parent, Vector &adj, std::vector<int> &subtree_size, int &max_deco)
{
  subtree_size [node] = 1; //initialisation
  for (int voisin : adj [node])
  {
    if (voisin == parent)
      continue;
    dfs(voisin, node, adj, subtree_size, max_deco);
    subtree_size [node] += subtree_size [voisin]; //ajoute la taille du sous arbre
  }
}
int main()
{
  int n;
  std::cin >> n;
  Vector adj(n);
  for (int i {0}; i < n-1; i++)
  {
    int a, b;
    std::cin >> a >> b;
    adj [a].push_back(b);
    adj [b].push_back(a);
  }
/*   std::cout << "--------------\n";
  for (int i {0}; i < n; i++)
  {
    std::cout << "PC " << i;
    for (int j {0}; j < (int) adj [i].size(); j++)
    {
      std::cout << " : " << adj [i][j];
    }
    std::cout << '\n';
  } */
  std::vector<int> sub_tree(n, 0);
  int max_deco {0};
  dfs(0, -1, adj, sub_tree, max_deco);
  for (int i {0}; i < n; i++)
  {
    for (int voisin : adj [i])
    {
      if (sub_tree [voisin] < sub_tree [i])
      {
        int taille1 {sub_tree [voisin]};
        int taille2 {n - taille1};
        max_deco = max_f(max_deco, min_f(taille1, taille2));
      }
    }
  }
  std::cout << max_deco << '\n';
  return 0;
}
