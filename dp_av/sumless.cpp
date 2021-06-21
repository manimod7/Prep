#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<int> nums {2,3,4,1,5};
    int target =5;
    int n =nums.size();
        int dp [n+1][target+1];
        for(int i=0;i<n+1;i++) 
            dp[i][0]=1;
        for(int j=1;j<target+1;j++)
            dp[0][j]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j];
            }
        } 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}