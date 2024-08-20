#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  int nombre_eleves, nombre_classes;
  // Lecture des entrées
  std::cin >> nombre_eleves;
  std::cin >> nombre_classes;
  
  // Calcul de la répartition des élèves dans les classes
  int eleves_par_classe {nombre_eleves / nombre_classes};
  int reste_eleves {nombre_eleves % nombre_classes};
  
  // Création d'un vecteur pour stocker le nombre d'élèves par classe
  std::vector<int> repartition(nombre_classes, eleves_par_classe);
  
  // Ajouter un élève supplémentaire dans les classes jusqu'à épuisement du reste
  for (int i {0}; i < reste_eleves; ++i)
  {
    repartition [i]++;
  }
  
  // Trier les classes par nombre d'élèves (les plus chargées en premier)
  std::sort(repartition.begin(), repartition.end(), std::greater<int>());
  
  // Affichage de la répartition
  for (int i {0}; i < nombre_classes; ++i)
  {
    std::cout << repartition [i] << std::endl;
  }
  return 0;
}
