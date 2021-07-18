#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 4e4 + 10;

vector<ll> count(vector<int> a)
{
  int n = a.size();
  vector<ll> res(n + 1);
  int i = 0;
  while (i < n)
  {
    if (a[i] == 0)
    {
      i++;
      continue;
    }
    int j = i;
    while (j < n && a[j] == 1)
      j++;
    for (int len = 1; len <= j - i; len++)
      res[len] += j - i - len + 1; //All lengths between 1 and j-i will be added times
    i = j;
  }
  return res;
}

void solved()
{
  int n, m;
  ll k, ans = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;
  auto A = count(a);
  auto B = count(b);
  for (int i = 1; i < A.size(); i++)
  {
    if (k % i == 0 && k / i <= m)
      ans += A[i] * B[k / i];
  }
  cout << ans;
}

int main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int t = 1;
  //cin >> t;
  while (t--)
  {
    solved();
  }

#ifdef LOCAL
  system("pause");
#endif
  return 0;
}