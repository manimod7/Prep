class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n,1);
        vector<int> lg(n,1); //lg[i] = max subarray till i such that nus[i]>nums[i-1]
        lg[0] = 1;
        ls[0] = 1;
        int ans = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                lg[i] = 1+ls[i-1];
                ls[i] = 1;
            }
            if(nums[i]<nums[i-1]){
                ls[i] = 1+lg[i-1];
                lg[i] = 1;
            }
            ans =max(ans,max(lg[i], ls[i]));
        }
        return ans;
        
    }
};