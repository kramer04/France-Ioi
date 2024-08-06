#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
// Définition de la structure d'un zoinxien
struct Zoinxien
{
  int x, y, tentacles, age;
};
// Fonction pour ajouter des amis basés sur la coordonnée x
int add_friends_by_x(const std::vector<std::vector<int>> &by_x, const std::vector<Zoinxien> &zoinxiens, int index, std::vector<bool> &visited, std::deque<int> &to_visit)
{
  int x {zoinxiens [index].x};
  int compteur {0};
  for (int friend_index : by_x [x])
  {
    if (!visited [friend_index])
    {
      to_visit.push_back(friend_index);
      visited [friend_index] = true;
      compteur++;
    }
  }
  return compteur;
}
// Fonction pour ajouter des amis basés sur la coordonnée y
int add_friends_by_y(const std::vector<std::vector<int>> &by_y, const std::vector<Zoinxien> &zoinxiens, int index, std::vector<bool> &visited, std::deque<int> &to_visit)
{
  int y {zoinxiens [index].y};
  int compteur {0};
  for (int friend_index : by_y [y])
  {
    if (!visited [friend_index])
    {
      to_visit.push_back(friend_index);
      visited [friend_index] = true;
      compteur++;
    }
  }
  return compteur;
}
// Fonction pour ajouter des amis basés sur le nombre de tentacules
int add_friends_by_tentacles(const std::vector<std::vector<int>> &by_tentacles, const std::vector<Zoinxien> &zoinxiens, int index, std::vector<bool> &visited, std::deque<int> &to_visit)
{
  int tentacles {zoinxiens [index].tentacles};
  int compteur {0};
  for (int friend_index : by_tentacles [tentacles])
  {
    if (!visited [friend_index])
    {
      to_visit.push_back(friend_index);
      visited [friend_index] = true;
      compteur++;
    }
  }
  return compteur;
}
// Fonction pour ajouter des amis basés sur l'âge (à plus ou moins 5 ans) avec approche de balayage
int add_friends_by_age(const std::vector<Zoinxien> &zoinxiens, int current_age, int index, std::vector<bool> &visited, std::deque<int> &to_visit)
{
  int compteur {0}, start {std::max(0, index - 5)}, end {std::min((int) zoinxiens.size() - 1, index + 5)};
  for (int i {start}; i <= end; ++i)
  {
    if (i != index && std::abs(zoinxiens [i].age - current_age) <= 5 && !visited [i])
    {
      to_visit.push_back(i);
      visited [i] = true;
      compteur++;
    }
  }
  return compteur;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<Zoinxien> zoinxiens(N);
  for (int i {0}; i < N; ++i)
  {
    std::cin >> zoinxiens [i].x >> zoinxiens [i].y >> zoinxiens [i].tentacles >> zoinxiens [i].age;
  }
  int max_x {0}, max_y {0}, max_tentacles {0}, max_age {0};
  for (const auto &z : zoinxiens)
  {
    if (z.x > max_x) max_x = z.x;
    if (z.y > max_y) max_y = z.y;
    if (z.tentacles > max_tentacles) max_tentacles = z.tentacles;
    if (z.age > max_age) max_age = z.age;
  }
  // Trie des zoinxiens par âge pour une recherche efficace
  std::sort(zoinxiens.begin(), zoinxiens.end(), [](const Zoinxien &a, const Zoinxien &b) {
    return a.age < b.age;
  });
  // Création des vecteurs pour les recherches par critères
  std::vector<std::vector<int>> by_x(max_x + 1), by_y(max_y + 1), by_tentacles(max_tentacles + 1);
  for (int i {0}; i < N; ++i)
  {
    by_x [zoinxiens [i].x].push_back(i);
    by_y [zoinxiens [i].y].push_back(i);
    by_tentacles [zoinxiens [i].tentacles].push_back(i);
  }
  std::vector<bool> visited(N, false);
  std::deque<int> to_visit;
  // Initialisation avec le premier zoinxien
  to_visit.push_back(0);
  visited [0] = true;
  int compteur {0};
  while (!to_visit.empty())
  {
    int current = to_visit.front();
    to_visit.pop_front();
    int current_age = zoinxiens [current].age;
    // Ajout des amis directs
    compteur += add_friends_by_x(by_x, zoinxiens, current, visited, to_visit);
    compteur += add_friends_by_y(by_y, zoinxiens, current, visited, to_visit);
    compteur += add_friends_by_tentacles(by_tentacles, zoinxiens, current, visited, to_visit);
    compteur += add_friends_by_age(zoinxiens, current_age, current, visited, to_visit);
  }
  std::cout << compteur << '\n';
  return 0;
}
