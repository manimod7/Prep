#include<bits/stdc++.h>
using namespace std;
int main(){          //1 2 3 4 5 6 7 8
    vector<int> price {1,5,8,9,10,17,17,20};
    int length =8;
    int len [8]{1,2,3,4,5,6,7,8};
    int n =price.size();
    int dp [n+1][length+1];
    for(int i =0;i<n+1;i++){
        dp[i][0] =0;
    };
    for(int j=0;j<length+1;j++)
        dp[0][j]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<length+1;j++){
            if(len[i-1]<=j)
                dp[i][j] =max(price[i-1] +dp[i][j-len[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
        
    }
    cout<<dp[n][length]<<endl; 
    return 0;
}