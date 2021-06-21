#include<bits/stdc++.h>

using namespace std;
int main(){
    
    int sum=0, size=0;
    cout<<"Enter size of array\n";
    cin>>size;
    vector<int> arr (size,0);
    cout<<"Enter elements of the array\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    cout<<"Sum is "<<sum<<endl;
    if(sum%2!=0)
        cout<< "Not possible since sum is odd\n";
    else{
        bool t [size+1][sum+1];
        for(int i=0;i<size+1;i++)
            t[i][0]=true;
        for(int j=1;j<sum+1;j++)
            t[0][j]=false;
        for(int i=1;i<size+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j)
                    t[i][j] =t[i-1][j-arr[i-1]]||t[i-1][j];    
                else
                    t[i][j] =t[i-1][j];
    }
}
    bool ans=false;
        for(int i=0;i<size+1;i++){
            ans =ans ||t[i][sum/2];
        }
        cout<<"The ans is "<<ans;
        }
    
    return 0;
}