class Solution {
public:
    int reverse(int x) {
        long long m=0;
        while(x!=0){
            int rem=x%10;
            m=m*10+rem;
            if(m<INT_MIN || m>INT_MAX){m=0;}
            x=x/10;
        }
        
        return m;
    }
};