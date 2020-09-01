class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string s="";
        
        do{
            string hour={char(A[0]+'0'),char(A[1]+'0')},min={char(A[2]+'0'),char(A[3]+'0')};
            s=stoi(hour)<24 && stoi(min)<60 ? (hour+":"+min) : s;
        }while(next_permutation(A.begin(),A.end()));
        return s;
    }
};
