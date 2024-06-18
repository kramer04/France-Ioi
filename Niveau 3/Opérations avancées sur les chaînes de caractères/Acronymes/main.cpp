#include <iostream>
#include <string>
#include <sstream>
void casse(std::string mot);
int main()
{
  std::ios::sync_with_stdio(false);
  std::string phrase{""}, mot{""}, accro{""};
  std::cin >> accro;
  int tAccro{(int)accro.size()};
  int nbTitres{0};
  std::cin >> nbTitres;
  std::cin.ignore();
  for (int i{0}; i < nbTitres; i++)
  {
    getline(std::cin, phrase);
    std::istringstream iss{phrase};
    std::string word [200] = {""};
    int count{0};
    std::string pAcro{""};
    while (iss >> word [count])
    {
      word [count][0] = toupper(word [count][0]);
      pAcro = pAcro + word [count][0];
      count++;
    }

    if (count == tAccro && pAcro == accro)
    {
      for (int j{0}; j < count; j++)
      {
        if (word [j][0] == accro [j])
        {
          casse(word [j]);
        }
      }
      std::cout << '\n';
    }
  }
  return 0;
}

void casse(std::string mot)
{
  for (int j{1}; j < (int)mot.size(); j++)
  {
    mot [j] = tolower(mot [j]);
  }
  std::cout << mot << " ";
}
