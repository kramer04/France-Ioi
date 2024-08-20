#include <iostream>
#include <cmath>
bool carre(int n)
{
  bool reponse {false};
  for (int i {1}; i <= n; i++)
  {
    if ((n % i) == 0)
    {
      if ((i * i) == n)
      {
        reponse = true;
        return reponse;
      }
    }
  }
  return reponse;
}
int main()
{
  int n;
  std::cin >> n;
  bool reponse = carre(n);
  if(reponse)
    std::cout << "Oui" << std::endl;
  else
    std::cout << "Non" << std::endl;
  
  return 0;
}
