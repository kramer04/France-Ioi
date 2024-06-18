// algorithme de la pile
//https://www.france-ioi.org/algo/task.php?idChapter=527&iOrder=1
#include <iostream>
#include <deque>
template <typename T>
T max_f(T count, T max)
{
  return (count > max) ? count : max;
}
template <typename T>
T min_f(T count, T max)
{
  return (count < max) ? count : max;
}
int empiler(std::deque<int> &pile, int date, int indice)
{
  if (indice > int(pile.size()-1))
    pile.push_back(date);
  else
    pile [indice] = date;
  indice++;
  return indice;
}
void depiler(int &indice)
{
  indice--;
}
bool viderPile(int indice)
{
  return indice == 0;
}
int main()
{
  int nbOperation;
  std::cin >> nbOperation;
  std::deque<int> stock;
  int indice {0};
  int minimum {0};
  for (int i {0}; i < nbOperation; i++)
  {
    int nbo, date;
    std::cin >> nbo >> date;
    minimum = max_f(date, minimum);
    if (nbo > 0)
      for (int j {0}; j < nbo; j++)
        indice = empiler(stock, date, indice);
    else
      for (int j {0}; j < -nbo; j++)
        depiler(indice);
  }
  while (!viderPile(indice))
  {
    depiler(indice);
    minimum = min_f(stock [indice], minimum);
  }
  std::cout << minimum << '\n';
  return 0;
}
