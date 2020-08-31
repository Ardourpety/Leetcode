class Solution {
public:
    
    class UF{
    public:    
        vector<int> size;
        vector<int> parent;
        int maxi;
        
        UF(int len){
            maxi=0;
            parent=vector<int>(len);
            size=vector<int>(len);
            for(int i=0;i<len;i++){
                size[i]=1;
                parent[i]=i;
            }   
        }
        
        int find(int x){
           if(x==parent[x]) return x;         
           return parent[x]=find(parent[x]);
       }       
        
        void Union(int x,int y){
            int rootx=find(x);
            int rooty=find(y);
            
            if(rootx==rooty)return;
            if(size[rootx]>size[rooty]){
                parent[rooty]=rootx;
                size[rootx]+=size[rooty];
            }
            else{
                parent[rootx]=rooty;
                size[rooty]+=size[rootx];
            }
            maxi=max(maxi,max(size[rootx],size[rooty]));
        }
    };
                        
    int largestComponentSize(vector<int>& A) {
        UF uf=UF(A.size());
        map<int,int> hash;
        
        for(int i=0;i<A.size();i++){
            for(int j=2;j*j<=A[i];j++){
                if(A[i]%j==0){
                    if(hash.find(j)!=hash.end()){
                        uf.Union(hash[j],i);
                    }
                    else{hash[j]=i;}
                    
                    if(hash.find(A[i]/j)!=hash.end()){
                        uf.Union(hash[A[i]/j],i);
                    }
                    else{hash[A[i]/j]=i;}
                }
                
            }
            if(hash.find(A[i])==hash.end()){hash[A[i]]=i;}
            else{uf.Union(i,hash[A[i]]);}
        }
        return uf.maxi;
    }
};
