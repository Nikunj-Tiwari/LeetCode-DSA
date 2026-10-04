class Solution {
public:
    int reverse(int x) {
        long long m=0;
        while(x!=0){
            int rem=x%10;
            m=m*10+rem;
            if(m<pow(-2, 31) || m>pow(2, 31)-1){m=0;}
            x=x/10;
        }
        
        return m;
    }
};