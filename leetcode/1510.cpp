// Both the players play optimally. dp[i] = true represents that for i th number, Alice can win. False means Alice loses.
// Lets assume Alice loses for n=j.
// Thus, if at any point i Alice can remove a square number such that the remaining number is equal to j, and j is false, then Alice can win at the point i.

// Time complexity: O(n sqrt(n) )
// Space complexity: O(n)

bool winnerSquareGame(int n)
{
  if (n == 0)
    return false;

  vector<bool> dp(n + 1, false);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j * j <= i; j++)
    {
      if (dp[i - (j * j)] == false)
      {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[n];
}