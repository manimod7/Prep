int maxSubArraySum(int a[], int size)
{
  int n = D.size();
  for (int i = 0; i < n; i++)
  {
    if (dir[i] == 'R')
      D[i] = -D[i];
  }

  pair<int, int> max_so_far = make_pair({0, INT_MIN}), max_ending_here = make_pair({0, 0});

  for (int i = 0; i < size; i++)
  {
    max_ending_here.second = max_ending_here.second + D[i];
    max_ending_here.first+=1;
  
    if (max_so_far.second < max_ending_here.second && max_ending_here.first %2==0){
      max_so_far.second = max_ending_here.second;
      max_so_far.first= max_ending_here.first;
    }
    if (max_ending_here.second < 0)
    {
      max_ending_here.second = 0;
      max_ending_here.first = 0;
    }
    
  }
  return max_so_far.second;
}