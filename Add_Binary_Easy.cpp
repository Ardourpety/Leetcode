class Solution {
public:
    string addBinary(string a, string b) {
            int i = a.length()-1;
            int j = b.length()-1;
            string ans="";
            int c=0;
        
            while(i>=0 || j>=0 || c==1){
                c+= i>=0? a[i--]-'0':0;
                c+= j>=0? b[j--]-'0':0;
                
                ans+='0'+(c%2);
                c/=2;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    
    
};
