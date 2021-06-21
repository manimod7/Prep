class Solution {
public:
    int distinctSubseqII(string s) {
        int mod =1e9+7;
        int n =s.size();
        unordered_map<char, int> mp;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*(dp[i-1]))%mod;
            char ch =s[i-1];
            if(mp.find(ch)!=mp.end()){
                int j =mp[ch];
                dp[i]=(dp[i]-dp[j-1]);
            }
            if(dp[i]<0)
                dp[i]+=mod;
            mp[ch] =i;
        }
        if(dp[n]<0)
            dp[n]+=mod;
        return dp[n]-1;
    }
};