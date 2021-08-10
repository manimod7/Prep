class Solution
{

public:
  // struct compare
  // {
  //     bool operator() (vector<int>&a, vector<int>&b) {
  //         return (a[0]*a[0]+a[1]*a[1]) >=(b[0]*b[0]+b[1]*b[1]);
  //     }
  // };
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
  {
    // sort(points.begin(),points.end(),[](vector<int> &a,vector<int>&b){
    //     return (a[0]*a[0]+a[1]*a[1]) <=(b[0]*b[0]+b[1]*b[1]);
    // });
    // points.resize(K);
    // return points;
    auto cmp = [](vector<int> &a, vector<int> &b)
    {
      return (a[0] * a[0] + a[1] * a[1]) >= (b[0] * b[0] + b[1] * b[1]);
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minq(points.begin(), points.end(), cmp);
    vector<vector<int>> res;
    while (K--)
    {
      res.push_back(minq.top());
      minq.pop();
    }
    return res;
  }
};