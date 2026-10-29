class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=j;
        vector<int> s(nums.size());
        while(i<=j){
            if(nums[i]*nums[i]>nums[j]*nums[j]){
                s[k]=nums[i]*nums[i];
                i++;
            }
            else{
                s[k]=nums[j]*nums[j];
                j--;
            }
            k--;
        }
        return s;
    }
};