class Solution
{

public:
  string frequencySort(string s)
  {

    // for(int i=0;i<256;i++) freq[i]=0;

    vector<int> freq(256, 0);

    for (char c : s)
      freq[c]++;

    sort(s.begin(), s.end(), [=](char a, char b)
         {
           if (freq[a] == freq[b])
             return a < b;

           else
             return freq[a] > freq[b];
         });

    return s;
  }
};