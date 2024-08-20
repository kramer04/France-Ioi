#include <iostream>
#include <vector>
int main()
{
  const int MAX = 1000;
  std::vector<bool> isPrime(MAX + 1, true);  // Initialisation d'un tableau pour marquer les nombres premiers
  isPrime [0] = false;  // 0 n'est pas un nombre premier
  isPrime [1] = false;  // 1 n'est pas un nombre premier
  for (int i {2}; i * i <= MAX; i++)
  {
    if (isPrime [i])
    {
      for (int j {i * i}; j <= MAX; j += i)
      {
        isPrime [j] = false;  // Marquer les multiples de i comme non premiers
      }
    }
  }
  //std::cout << "Nombres premiers entre 1 et " << MAX << " : " << std::endl;
  for (int i {2}; i <= MAX; i++)
  {
    if (isPrime [i])
    {
      std::cout << i << '\n';  // Affichage des nombres premiers
    }
  }
  std::cout << std::endl;
  return 0;
}
