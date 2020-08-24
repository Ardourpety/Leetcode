class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for(auto& word:words){
            trie.insert_reverse(word);
            if(word.length()>longest_word)
                longest_word=word.length();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(),letter);
        
        if(queries.size()>longest_word)queries.pop_back();
        
        Trie *cur=&trie;
        
        for(auto it=queries.begin();it!=queries.end();it++){
            if (cur->is_leaf) return true;
            if (cur->children[*it -'a'] == NULL) return false;
            cur = cur->children[*it-'a'];            
        }
        return cur->is_leaf;
    }
    
    
private:
    class Trie{
    public:
        Trie(){
            this->is_leaf=false;
            
            for(int i=0;i<26;i++){
                this->children[i]=NULL;}
        }
        
        void insert_reverse(string words){
            reverse(words.begin(),words.end());
            
            Trie* root=this;
            
            for(int i=0;i<words.length();i++){
                int index=words[i]-'a';
                if(root->children[index]==NULL) root->children[index]=new Trie();
                
                root=root->children[index];
            }
            root->is_leaf=true;
        }
        
        bool is_leaf;
        Trie* children[26];
    };
    
    Trie trie;
    vector<char> queries;
    int longest_word=0;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
