class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        
        
        for(int i=0;i<nums.size();i++){
            long x=nums[i];
            if(i>k){
                s.erase(nums[i-k-1]);        
            }
            
            auto p=s.lower_bound(x-t);
            
            if(p!=s.end() && *p-x<=t) return true;
            
            s.insert(x);
        }
        return false;
    }
};
