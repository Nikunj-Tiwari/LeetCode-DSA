class Solution {
public:
    int strStr(string haystack, string needle) {
        int a=-1,c,i=0;
        while(i<haystack.size()){
            c=0;
            for(int j=0;j<needle.size();j++){
                if(haystack[i+j]==needle[j]){
                    c++;
                }
                else{
                    break;
                }
            }
            if(c==needle.size()){
                a=i;
                break;
            }
            i++;
        }
        return a;

    }
};