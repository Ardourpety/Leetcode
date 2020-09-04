class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v(26,0);
        vector<int> ans;
        
        for(int i=0;i<S.size();i++){
            v[S[i]-'a']=i;
        }
        
        
        int k=0,j=0;
        
        for(int i=0;i<S.size();i++){
            j=max(j,v[S[i]-'a']);
            
            if(i==j){
                ans.push_back(i-k+1);
                k=i+1;
            }
        }
        return ans;
    }
};
