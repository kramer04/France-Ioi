#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <stack>     // stack
// Représentation d'un canard / noeud
struct Node {
  int id;     // index d'entrée (0..N-1)
  int I;      // intelligence
  int C;      // charisme
  int left;   // indice fils gauche (-1 si absent)
  int right;  // indice fils droit  (-1 si absent)
  int parent; // indice parent      (-1 si racine)
};
// ----- Affichage (itératif) : (gauche)id(droite), en omettant les parenthèses vides -----
void print_parenthesized(const std::vector<Node>& a, int root)
{
  if (root == -1) { std::cout << '\n'; return; }
  struct Frame { int u; int stage; };
  // stages :
  // 0 = avant gauche (si gauche existe, on ouvre '(' et on descend)
  // 1 = après gauche  (on ferme ')', puis on imprimera l'id)
  // 2 = id imprimé, avant droit (si droit existe, on ouvre '(' et on descend)
  // 3 = après droit   (on ferme ')')
  std::vector<Frame> st;
  st.reserve(a.size() * 2 + 5);
  st.push_back({root, 0});
  while (!st.empty())
  {
    Frame fr = st.back(); st.pop_back();
    int u = fr.u;
    switch (fr.stage)
    {
    case 0: // avant gauche
      if (a[u].left != -1)
      {
        std::cout << '(';
        st.push_back({u, 1});           // revenir après le sous-arbre gauche
        st.push_back({a[u].left, 0});   // descendre à gauche
      }
      else
      {
        // pas de gauche : imprimer l'id et gérer le droit
        std::cout << a[u].id;
        st.push_back({u, 2});
      }
      break;
    case 1: // après gauche : fermer ')' puis imprimer l'id
      std::cout << ')';
      std::cout << a[u].id;
      st.push_back({u, 2});
      break;
    case 2: // avant droit
      if (a[u].right != -1)
      {
        std::cout << '(';
        st.push_back({u, 3});           // revenir après le droit
        st.push_back({a[u].right, 0});  // descendre à droite
      }
      break;
    case 3: // après droit
      std::cout << ')';
      break;
    }
  }
  std::cout << '\n';
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  if (!(std::cin >> N)) return 0;
  std::vector<Node> a(N);
  for (int i = 0; i < N; ++i)
  {
    int I, C;
    std::cin >> I >> C;
    a[i] = {i, I, C, -1, -1, -1};
  }
  if (N == 0) { std::cout << '\n'; return 0; }
  // 1) Ordre infixe = tri par intelligence croissante,
  //    et en cas d'égalité d'intelligence, **charisme croissant**
  //    (pour forcer les égalités à partir à gauche, comme l'exemple).
  std::vector<int> ord(N);
  for (int i = 0; i < N; ++i) ord[i] = i;
  std::sort(ord.begin(), ord.end(), [&](int u, int v) {
    if (a[u].I != a[v].I) return a[u].I < a[v].I;
    if (a[u].C != a[v].C) return a[u].C < a[v].C; // clé pour "égalités à gauche"
    return a[u].id < a[v].id;                    // stabilité déterministe
    });
  // 2) Construction de l'arbre cartésien (tas max sur C) en O(N) via pile monotone
  std::stack<int> st; // indices dans 'a'
  for (int idx : ord)
  {
    int last = -1;
    // Dépiler tant que le sommet est moins charismatique
    while (!st.empty() && a[st.top()].C < a[idx].C)
    {
      last = st.top();
      st.pop();
    }
    // 'last' devient le fils gauche du courant
    a[idx].left = last;
    if (last != -1) a[last].parent = idx;
    // Si la pile n'est pas vide, le courant devient le fils droit du sommet
    if (!st.empty())
    {
      a[st.top()].right = idx;
      a[idx].parent = st.top();
    }
    st.push(idx);
  }
  // 3) Trouver la racine (noeud sans parent)
  int root = -1;
  for (int i = 0; i < N; ++i)
  {
    if (a[i].parent == -1) { root = i; break; }
  }
  // 4) Affichage
  print_parenthesized(a, root);
  return 0;
}
