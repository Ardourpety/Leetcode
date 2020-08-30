class Solution {
public:

    int findIndex(vector<int>& B,int n){
        for(int i=0;i<B.size();i++){
            if(B[i]==n) return i;
        }
        return -1;
    }
    
    
    
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        
        for(int i=A.size();i>0;i--){
            int index=findIndex(A,i);
            ans.push_back(index+1);
            reverse(A.begin(),A.begin()+index+1);
            ans.push_back(i);
            reverse(A.begin(),A.begin()+i);
        }
        return ans;
    }
};
