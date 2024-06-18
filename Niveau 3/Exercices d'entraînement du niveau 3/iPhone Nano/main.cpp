#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using Mot = std::vector<std::string>;
//fonctions
std::string cherche(std::string &dico, std::vector<std::string> &mt);
int main()
{
  std::ios::sync_with_stdio(false);
  int D;
  std::cin >> D;
  Mot mot_dico;
  for (int i{0}; i < D; i++)
  {
    std::string s{""};
    std::cin >> s;
    mot_dico.push_back(s);
  }
  size_t N{0};
  std::cin >> N;
  Mot lettre_tape;
  for (size_t i{0}; i < N; i++)
  {
    std::string s{""};
    std::cin >> s;
    lettre_tape.push_back(s);
  }
  Mot trouve{};
  for (int i{0}; i < D; i++)
  {
    if (mot_dico [i].size() == N)
    {
      if (cherche(mot_dico [i], lettre_tape) == mot_dico [i])
      {
        trouve.push_back(mot_dico [i]);
      }
    }
  }
 /*  for (auto d : trouve)
    std::cout << d << " ";
  std::cout << std::endl; */
  std::cout << trouve [0] << std::endl;
  return 0;
}
std::string cherche(std::string &dico, Mot &mt)
{
  std::string mot_renvoye;
  for (size_t i{0}; i < mt.size(); i++)
  {
    auto d = std::find(mt [i].begin(), mt [i].end(), dico [i]);
    if (d != mt [i].end())
      mot_renvoye += *d;
    else
      return mot_renvoye;
  }
  return mot_renvoye;
}
