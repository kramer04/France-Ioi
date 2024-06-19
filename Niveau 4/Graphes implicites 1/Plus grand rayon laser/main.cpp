#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using Paire = std::vector<std::pair<std::pair<int, int>, std::pair<char, bool>>>;
struct Rayon
{
  Paire node;
};
std::vector<std::vector<char>>lab(1000 + 1);
std::vector<Rayon> noeud(1000 * 1000 + 1);
int row {0}, col {0};
std::pair<int, int> next_node(int ito, char c, int cols, int &k)
{
  int i = ito / cols;
  int j = ito % cols;
  std::pair<int, int> it({-1, -1});
  if (lab [i][j] == '\\' && c == 'd')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'b')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '\\' && c == 'g')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'h')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '\\' && c == 'b')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'd')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '\\' && c == 'h')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'g')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '/' && c == 'g')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'b')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '/' && c == 'd')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'h')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '/' && c == 'b')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'g')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  else if (lab [i][j] == '/' && c == 'h')
  {
    for (; k < (int) noeud [ito].node.size(); k++)
    {
      if (noeud [ito].node [k].second.first == 'd')
      {
        it.first = noeud [ito].node [k].first.first;
        it.second = noeud [ito].node [k].first.second;
        return it;
      }
    }
  }
  return it;
}
int max_f(int count, int max)
{
  return (count > max) ? count : max;
}
int dfs(int i, int max, int count)
{
  int ligne_node {0}; // rang dans le node
  char sens {};// direction vers gauche, droite, bas ou haut
  // détermine la paire vers laquelle se diriger
  std::pair<int, int> pointA_pointB;
  //dans le cas d'une boucle
  int count1 {0}, max1 {0}, max2 {0}, pos {0};
  bool boucle {false}, va_dans_mur {false};
  for (int j {0}; j < (int) noeud [i].node.size(); j++)
  {
    bool dir {true}, sortie {false};
    ligne_node = j;
    pointA_pointB = std::make_pair(noeud [i].node [ligne_node].first.first, noeud [i].node [ligne_node].first.second);
    int pointA {pointA_pointB.first}, pointB {pointA_pointB.second};
    //coordonnées des point A et B
    int x1 {pointA / col}, y1 {pointA % col}, x2 {pointB / col}, y2 {pointB % col};
    //stocke la paire de départ pour contrôler si le laser boucle ou les sorties anticipées
    std::pair<int, int>paire_depart = pointA_pointB;
    if (noeud [i].node [ligne_node].second.second)
    {
      while (dir)
      {
        //déjà vu
        pos = 0;
        sortie = true;
        noeud [pointA].node [ligne_node].second.second = false;
        for (; pos < (int) noeud [pointB].node.size(); pos++)
        {
          if (noeud [pointA].node [ligne_node].first.first == noeud [pointB].node [pos].first.second && noeud [pointA].node [ligne_node].first.second == noeud [pointB].node [pos].first.first)
          {
            break;
          }
        }
        noeud [pointB].node [pos].second.second = false;
        count += std::abs(x1 - x2) + std::abs(y1 - y2);
        max = max_f(count, max);
        // nœud suivant
        sens = noeud [pointA].node [ligne_node].second.first;
        ligne_node = 0;
        pointA_pointB = next_node(pointB, sens, col, ligne_node);
        pointA = pointA_pointB.first;
        pointB = pointA_pointB.second;
        x1 = pointA / col;
        y1 = pointA % col;
        x2 = pointB / col;
        y2 = pointB % col;
        //test sortie
        int ax {paire_depart.first / col}, ay {paire_depart.first % col};
        char direction {noeud [paire_depart.second].node [pos].second.first};
        char type_noeud {lab [ax][ay]};
        if (direction == 'g' && ((type_noeud == '\\' && ax == 0) || (type_noeud == '/' && ax == row - 1)))
        {
          sortie = false;
        }
        else if (direction == 'h' && ((type_noeud == '\\' && ay == 0) || (type_noeud == '/' && ay == col - 1)))
        {
          sortie = false;
        }
        if (pointA == -1 && pointB == -1)
        {
          if (sortie && lab [ax][ay] != '.')
          {
            count1 += count;
            max = max_f(count1, max);
            count = 0;
          }
          else
          {
            count1 = 0;
            count = 1;
          }
          dir = false;
          va_dans_mur = true;
          max2 = max;
        }
        // si le laser boucle
        if (paire_depart.first == pointA && paire_depart.second == pointB)
        {
          max1 = max_f(count - 1, max1);
          count = 1;
          dir = false;
          boucle = true;
          if (max - 1 == max1)
            max = max1;
        }
        //boucles et chemins
        else if (va_dans_mur && boucle && paire_depart.first == pointA && paire_depart.second == pointB)
        {
          if (max1 > max2)
          {
            max = max1;
          }
        }
      }
    }
  }
  return max;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin >> row >> col;
  for (int i {0}; i < row; i++)
  {
    for (int j {0}; j < col; j++)
    {
      char c {};
      std::cin >> c;
      lab [i].push_back(c);
    }
  }
  for (int i {0}; i < row; ++i)
  {
    int j {0};
    if (lab [i][j] != '.' || (j < col && lab [i][j] == '.'))
    {
      for (int k {1}; k < col; k++)
      {
        if (lab [i][k] != '.' || (lab [i][k] == '.' && ((k == 0 || k == col - 1))))
        {
          noeud [i * col + j].node.push_back(std::make_pair(std::make_pair(i * col + j, i * col + k), std::make_pair('d', true)));
          noeud [i * col + k].node.push_back(std::make_pair(std::make_pair(i * col + k, i * col + j), std::make_pair('g', true)));
          j = k;
        }
      }
    }
  }
  for (int j {0}; j < col; ++j)
  {
    int i {0};
    if (lab [i][j] != '.' || (i < row && lab [i][j] == '.'))
    {
      for (int k {1}; k < row; k++)
      {
        if (lab [k][j] != '.' || (lab [k][j] == '.' && ((k == 0 || k == row - 1))))
        {
          noeud [i * col + j].node.push_back(std::make_pair(std::make_pair(i * col + j, k * col + j), std::make_pair('b', true)));
          noeud [k * col + j].node.push_back(std::make_pair(std::make_pair(k * col + j, i * col + j), std::make_pair('h', true)));
          i = k;
        }
      }
    }
  }
  int max {0};
  for (int i {0}; i < row * col; i++)
  {
    if (noeud [i].node.size())
      max = dfs(i, max, 1);
  }
  std::cout << max << '\n';
  return 0;
}
