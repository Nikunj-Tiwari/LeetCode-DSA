class Solution {
public:
    int romanToInt(string s) {
        int v=0,a[s.size()];
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                a[i]=1;
            }
            if(s[i]=='V'){
                a[i]=5;
            }
            if(s[i]=='X'){
                a[i]=10;
            }
            if(s[i]=='L'){
                a[i]=50;
            }
            if(s[i]=='C'){
                a[i]=100;
            }
            if(s[i]=='D'){
                a[i]=500;
            }
            if(s[i]=='M'){
                a[i]=1000;
            }
            }
            for(int  i=0;i<s.size();i++){
                int r=1;
                if(i==s.size()-1){r=1;}
                else if(a[i]<a[i+1]){
                    r=-1;
                }
                v +=a[i]*r;
            }
            return v;
        }
};