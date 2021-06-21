class Solution
{
public:
  void solve(vector<int> &v, int index, int k, int &ans)
  {

    //Base condition
    if (v.size() == 1)
    {
      ans = v[0];
      return;
    }
    //Recursion
    index = (index + k - 1) % v.size();
    v.erase(v.begin() + index);
    solve(v, index, k, ans);
  }
  int safePos(int n, int k)
  {
    // code here
    int ans = 0, index = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back(i + 1);
    }
    solve(v, index, k, ans);
    return ans;
  }
};