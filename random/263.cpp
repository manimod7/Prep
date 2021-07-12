//Ugly Number Leetcode
//Check whether a number has other prime factors than 2,3 and 5
class Solution
{
public:
  bool isUgly(int num)
  {
    if (num == 0)
      return false;
    while (num % 2 == 0)
      num /= 2;
    while (num % 3 == 0)
      num /= 3;
    while (num % 5 == 0)
      num /= 5;
    return num == 1;
  }
};