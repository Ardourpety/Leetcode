class Solution {
public:
    
    void backtrack(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        
        for(int j=i;j<nums.size();j++){
            sub.push_back(nums[j]);
            backtrack(nums,j+1,sub,subs);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        
        backtrack(nums,0,sub,subs);
        
        return subs;
    }
};
