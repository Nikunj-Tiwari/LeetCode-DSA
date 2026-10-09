class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,a=-1;
        for(int i=0;i<s.size();i++){
            c++;
            if(s[i]==' '){
                if(i==0){
                    c=0;
                    continue;
                }
                if(s[i-1]!=' '){
                    a=c-1;
                }
                c=0;
            }
        }
        if(s[s.size()-1]!=' '){
            a=c;
        }
        return a;
    }
};