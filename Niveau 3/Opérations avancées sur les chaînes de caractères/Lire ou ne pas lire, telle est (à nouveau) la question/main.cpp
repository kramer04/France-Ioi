#include <iostream>
#include <string>
//#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  int nbLivres{0};
  std::cin >> nbLivres;
  std::cin.ignore();
  std::string line [100];
  std::string s{""};
  //int count{0};
  getline(std::cin, line [0]);
  for (int i{1}; i < nbLivres; i++)
  {
    getline(std::cin, s);
    if (s > line [i - 1])
    {
      line [i] = s;
      //count++;
    }
    else
    {
      i -= 1;
      nbLivres -= 1;
    }
  }
  //std::sort(line, line + nbLivres);
  //std::cout << "------------------\n";
  for (int i{0}; i < nbLivres; i++)
  {
    std::cout << line [i] << '\n';
  }
  return 0;
}
