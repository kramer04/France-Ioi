#include <iostream>
#include <string>
#include <vector>
#include <map>
struct Position
{
  int x, y;
  bool existe;
};
//fonctions
std::vector<Position> position_billes(std::vector<std::string> &grille, int nbl, int nbc);
void mouvement(std::vector<std::string> &grille, Position &p, char dir, int &nbBilles) noexcept;
int main()
{
  std::ios::sync_with_stdio(false);
  int l{0}, c{0};
  std::cin >> l >> c;
  std::vector<std::string> lab;
  for (int i{0}; i < l; i++)
  {
    std::string s{};
    std::cin >> s;
    lab.push_back(s);
  }
  int nb_mouvement{0};
  std::cin >> nb_mouvement;
  std::string dir{};
  std::cin >> dir;
  //combien de billes et position de départ de chaque bille ?
  int nb_billes{0};
  std::vector<Position> pos;
  for (int i{1}; i < l - 1; i++)
  {
    for (int j{1}; j < c - 1; j++)
    {
      if (lab [i][j] == 'x')
      {
        pos.push_back({i, j, true});
        nb_billes++;
      }
    }
  }
  int nbb{nb_billes};
  for (size_t i{0}; i < dir.size(); i++)
  {
    int j{0};
    if (dir [i] == 'O' || dir [i] == 'N')
    {
      pos = position_billes(lab, l, c);
      while (j < (int)pos.size())
      {
        if (pos [j].existe)
        {
          mouvement(lab, pos [j], dir [i], nbb);
        }
        j++;
      }
    }
    else
    {
      pos = position_billes(lab, l, c);
      j = (int)pos.size() - 1;
      while (j >= 0)
      {
        if (pos [j].existe)
        {
          mouvement(lab, pos [j], dir [i], nbb);
        }
        j--;
      }
    }
  }
  std::cout << nbb << std::endl;
  return 0;
}
std::vector<Position> position_billes(std::vector<std::string> &grille, int nbl, int nbc)
{
  std::vector<Position> posbilles;
  for (int i{1}; i < nbl - 1; i++)
  {
    for (int j{1}; j < nbc - 1; j++)
    {  
      if (grille [i][j] == 'x')
      {
        posbilles.push_back({i, j, true});
      }
    }
  }
  return posbilles;
}
//mouvement de la bille
void mouvement(std::vector<std::string> &grille, Position &p, char dir, int &nbBilles) noexcept
{
  grille [p.x][p.y] = '.';
  struct Valeurs
  {
    int &coord, delta;
  };
  const std::map<char, Valeurs> valeurs = {
    {'S', {p.x, 1}},
     {'E', {p.y, 1}},
     {'N', {p.x, -1}},
     {'O', {p.y, -1}},
  };
  const Valeurs &valsPris = valeurs.find(dir)->second;
  while (true)
  {
    valsPris.coord += valsPris.delta;
    if (grille [p.x][p.y] == 'O')
    {
      p.existe = false;
      nbBilles--;
      break;
    }
    if (grille [p.x][p.y] == '#' || grille [p.x][p.y] == 'x')
    {
      valsPris.coord -= valsPris.delta;
      grille [p.x][p.y] = 'x';
      break;
    }
  }
}
