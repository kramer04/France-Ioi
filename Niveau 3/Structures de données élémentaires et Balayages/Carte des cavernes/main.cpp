#include <iostream>
#include <algorithm>
#include <string>
int main()
{
  int nbCaractere{0};
  std::cin >> nbCaractere;
  std::string chemin{""};
  std::cin.ignore();
  getline(std::cin, chemin);
  int pos{0};
  bool sens{false};
  int pO{(int)std::count(chemin.begin(),chemin.end(),'(')};
  int pF{(int)std::count(chemin.begin(),chemin.end(),')')};
  int nbP{pO - pF};
  
  for (int i{0}; i < nbCaractere; i++)
  {
    if (chemin [i] == '(')
    {
      pos++;
      sens = false;
    }
    if (chemin [i] == ')')
    {
      pos--;
      sens = true;
    }
  }
  if (pos == 0 && sens && nbP == 0)
    std::cout << 1 << std::endl;
  else
    std::cout << 0 << std::endl;
  
  return 0;
}
