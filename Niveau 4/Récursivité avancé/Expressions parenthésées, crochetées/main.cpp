#include <iostream>
#include <stack>
bool isBalancedRecursive(const std::string &expr, int &i, std::stack<char> &s)
{
  if (i >= (int)expr.length())
    return s.empty();
  char c = expr [i];
  switch (c)
  {
  case '(':
  case '[':
  case '{':
  case '<':
    s.push(c);
    break;
  case ')':
    if (s.empty() || s.top() != '(')
      return false;
    s.pop();
    break;
  case ']':
    if (s.empty() || s.top() != '[')
      return false;
    s.pop();
    break;
  case '}':
    if (s.empty() || s.top() != '{')
      return false;
    s.pop();
    break;
  case '>':
    if (s.empty() || s.top() != '<')
      return false;
    s.pop();
    break;
  }
  ++i;
  return isBalancedRecursive(expr, i, s);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string expr;
  std::getline(std::cin, expr);
  std::stack<char> s;
  int i = 0;
  if (isBalancedRecursive(expr, i, s))
    std::cout << "yes" << std::endl;
  else
    std::cout << "no" << std::endl;
  return 0;
}
