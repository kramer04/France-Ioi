#include <iostream>
#include <queue>
#include <unordered_set>
// Structure représentant un état du jeu
struct State
{
  int value;  // La valeur de l'état
  int cost;   // Le coût pour atteindre cet état
};
int main()
{
  // Lecture des entrées
  int a, b, c, d, n, m;
  std::cin >> a >> b >> c >> d >> n >> m;
  // Initialisation de la file d'états à traiter
  std::queue<State> states;
  states.push({n, 0});
  // Initialisation de l'ensemble des états déjà visités
  std::vector<int> visited(100005);
  //visited.insert(n);
  // Parcours en largeur de l'arbre des états possibles
  while (!states.empty())
  {
    State curr = states.front();
    states.pop();
    // Test de l'état courant pour savoir si on a atteint la valeur M
    if (curr.value == m)
    {
      std::cout << "1" << '\n';
      return 0;
    }
    // Génération des nouveaux états possibles en appliquant les 4 opérations
    int newCost = curr.cost + 1;
    if (curr.value + a <= 100000 && !visited[curr.value + a])
    {
      states.push({curr.value + a, newCost});
      visited[curr.value + a] = 1;
    }
    if (curr.value - b >= 0 && !visited[curr.value - b])
    {
      states.push({curr.value - b, newCost});
      visited[curr.value - b] = 1;
    }
    if (curr.value * c <= 100000 && !visited[curr.value * c])
    {
      states.push({curr.value * c, newCost});
      visited[curr.value * c] = 1;
    }
    if (d != 0 && curr.value % d == 0 && curr.value / d >= 0 && !visited[curr.value / d])
    {
      states.push({curr.value / d, newCost});
      visited[curr.value / d] = 1;
    }
  }
  // Si on a parcouru tout l'arbre sans trouver la valeur M, c'est qu'il n'y a pas de solution
  std::cout << "0" << '\n';
  return 0;
}
