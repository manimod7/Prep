vector<double> runningMedian(vector<int> a) {
    int n = a.size();
   vector<double> res(n);
    if(n==0)
        return res;
    res[0] = a[0];
    
    for(int i=1;i<n;i++){
        if(i%2==1)
            res[i] = (double) (a[i/2]+a[i/2+1])/2.0;
        else
            res[i] = (double) a[i/2];
    }
    return res;
}
