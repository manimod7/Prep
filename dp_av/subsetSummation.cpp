#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,difference;
    cout<<"Enter size of Set\n";
    cin>>n;
    int set[n];
    cout<<"Enter all elements of set of size "<<n<<endl;
    for(int i=0;i<n;i++)
        cin>>set[i];
    cout<<"Enter the difference between sum of the 2 subsets\n";
    cin>>difference;
    int totalSum =0;
    for(int i=0;i<n;i++)
        totalSum+=set[i];
    sum = (totalSum+difference)/2;
    //If we take two sets S1 & S2 we need to find number of sets S1 and S2 such that S1 - S2 = given difference
    //S1 + S2 = totalSum
    //S1 - S2 = difference
    //2S1 = totalSum + difference

    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = 1;
    for(int j=1;j<sum+1;j++)
        dp[0][j] =0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(set[i-1]<=j)
                dp[i][j] =dp[i-1][j]+dp[i-1][j-set[i-1]];
            else 
                dp[i][j] =dp[i-1][j];
        }
    }
    cout<<dp[n][sum];
    return 0;
}