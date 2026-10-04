class Solution {
public:
    bool isPalindrome(int x) {
        int n,y=x;
        long long m=0;
        while(y>0){
            n=y%10;
            m=m*10+n;
            y=y/10;
        }
        return x==m;
    }
};