#include <iostream>
#include <cmath>
#include <limits>

int main()
{
  double seuil;
  std::cin >> seuil;
  
  // Définir les bornes de la recherche
  int low {3};
  int high {500000000};
  int result {high};
  
  // Recherche binaire pour trouver la valeur de k
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    double value = std::log(mid) / mid;
    if (value <= seuil)
    {
      result = mid;  // k potentiel trouvé, on continue vers le plus petit
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
