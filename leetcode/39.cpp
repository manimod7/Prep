class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &nums, int start, int end, vector<int> currSum, int target){
        
        if(target==0){
            res.push_back(currSum);
            return;
        }
        if(target<0)
            return;
        if(start>end)
            return ;
        solve(nums, start+1,end,currSum, target);
        
        currSum.push_back(nums[start]);
        
        solve(nums, start, end, currSum, target - nums[start]);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currSum;
        solve(candidates,0,candidates.size()-1,currSum, target);
        return res;
    }
};