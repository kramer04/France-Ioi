#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>
#include <tuple>
#include <vector>
bool isInteger(double number)
{
  // Vérifie si le nombre est égal à sa partie entière
  return std::floor(number) == number;
}
int main()
{
  int longueurMax;
  std::cin >> longueurMax;
  std::array<double, 3> valeurs;
  std::vector<std::vector<double>> controle;
  for (int i {1}; i <= longueurMax; i++)
  {
    valeurs [0] = i;
    for (int j {i + 1}; j <= longueurMax; j++)
    {
      valeurs [1] = j;
      valeurs [2] = sqrt(std::abs(i * i - j * j));
      if (valeurs [2] != 0 && i < j && isInteger(valeurs [2]))
      {
        // Vérifier si le tableau controle est vide ou si la dernière entrée est différente
        if (controle.empty() ||
            controle.back() [0] != valeurs [0] ||
            controle.back() [1] != valeurs [1] ||
            controle.back() [2] != valeurs [2])
        {
          // Ajouter la nouvelle combinaison au vecteur controle
          controle.push_back({valeurs [0], valeurs [1], valeurs [2]});
        }
      }
    }
  }
  for (size_t i {0}; i < controle.size(); i++)
  {
    std::sort(controle [i].begin(), controle [i].end());
  }
  // Trier le tableau entier pour que les doublons soient consécutifs
  std::sort(controle.begin(), controle.end());
  // Supprimer les doublons
  auto last = std::unique(controle.begin(), controle.end());
  controle.erase(last, controle.end());
  for (auto &v : controle)
    std::cout << v [0] << " " << v [1] << " " << v [2] << '\n';
  return 0;
}
