#include <iostream>
#include <string>
size_t longestPalSubstr(std::string str);
int main()
{
  std::string str{""}, palindrome{""};
  std::cin >> str;
  std::cout << longestPalSubstr(str) << std::endl;
  return 0;
}
size_t longestPalSubstr(std::string str)
{
  size_t n{str.size()};
  if (n < 2)
    return n;
  size_t maxLength{1};
  size_t low, high;
  for (size_t i{0}; i < n; i++)
  {
    low = i - 1;
    high = i + 1;
    while (high < n && str [high] == str [i]) //increment 'high'                                 
      high++;
    while (str [low] == str [i]) // decrement 'low'                  
      low--;
    while (high < n && str [low] == str [high])
    {
      low--;
      high++;
    }
    size_t length = high - low - 1;
    if (maxLength < length)
      maxLength = length;
  }
  return maxLength;
}
