        int ans =0;
        for(int i=0;i<=target;i++){
            ans+=dp[n][i];
        }
    cout<<ans;