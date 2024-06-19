#include <iostream>
#include <deque>
#include <algorithm>
std::deque<int> subtract(const std::deque<int> &a, const std::deque<int> &b, int base)
{
  std::deque<int> result;
  int carryoff {0};
  for (size_t i {0}; i < a.size(); i++)
  {
    carryoff = a [i] - carryoff - (i < b.size() ? b [i] : 0);
    result.push_front((carryoff + base) % base);
    carryoff = carryoff < 0;
  }
  if (carryoff)
  {
    result = subtract(b, a, base);
    result.insert(result.begin(), 0);
  }
  return result;
}
bool operator<(std::deque<int> &a, std::deque<int> &b)
{
  size_t sa = a.size(), sb = b.size();
  if (sa < sb)
    return true;
  else if (sa > sb)
    return false;
  else
  {
    auto ita = a.end() - 1;
    auto itb = b.end() - 1;
    while (ita != a.begin() - 1 && itb != b.begin() - 1)
    {
      if (*itb > *ita)
        return true;
      else if (*itb < *ita)
        return false;
      ita--;
      itb--;
    }
  }
  return false;
}
void resize_pop_back(std::deque<int> &d)
{
  while (d.back() == 0)
    d.pop_back();
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  int base, n1, n2;
  std::cin >> base >> n1 >> n2;
  std::deque<int> a(n1), b(n2);
  for (int i {n1 - 1}; i >= 0; i--)
    std::cin >> a [i];
  for (int i {n2 - 1}; i >= 0; i--)
    std::cin >> b [i];
  if (a.size() > 1 && a.back() == 0)
    resize_pop_back(a);
  if (b.size() > 1 && b.back() == 0)
    resize_pop_back(b);
  bool negative = false;
  if (a < b)
  {
    std::swap(a, b);
    negative = true;
  }
  std::deque<int> result = subtract(a, b, base);
  while (result.size() > 1 && result.front() == 0)
    result.pop_front();
  if (result.empty())
  {
    std::cout << '0' << '\n';
    return 0;
  }
  if (negative)
    std::cout << "- ";
  for (size_t i {0}; i < result.size(); i++)
    std::cout << result [i] << " ";
  std::cout << '\n';
  return 0;
}
