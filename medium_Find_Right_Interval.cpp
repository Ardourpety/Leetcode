class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mm;
        vector<int> v;
        
        
        for(int i=0;i<intervals.size();i++){
            mm[intervals[i][0]]=i;    
        }
        
        for(auto in:intervals){
            auto iter=mm.lower_bound(in[1]);
            if(iter==mm.end()) v.push_back(-1);
            else v.push_back(iter->second);
        }
        
        return v;
    }
};
