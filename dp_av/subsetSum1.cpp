#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum=0,size=0;   
    int difference;
    cout<<"Enter the difference between subsets\n";
    cin>>difference;
    cout<<"Enter the size of array\n";
    cin>>size;
    vector<int> arr(size,0);
    cout<<"Enter the elements of array\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int sumall=0;
    for(int i=0;i<size;i++)
        sumall+=arr[i];
    sum=(difference+sumall)/2;
    int t[size+1][sum+1];
    for(int i=0;i<size+1;i++)
        t[i][0]=1;
    for(int j=1;j<sum+1;j++)
        t[0][j]=0;
    for(int i=1;i<size+1;i++)
    {
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            else
                t[i][j]=t[i-1][j];
        }
    }   
    cout<<t[size][sum];
    return 0;
}