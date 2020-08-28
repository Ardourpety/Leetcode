// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int m,n;
        
        while((m=rand7())>6);
        while((n=rand7())>5);
        
        return m%2? n:n+5;
    }
};
