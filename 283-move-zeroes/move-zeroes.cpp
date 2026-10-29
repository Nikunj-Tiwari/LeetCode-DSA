class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int j=i;
            if(nums[i]==0){
                while(j<nums.size()-1 && nums[j]==0){
                j++;
                }
                nums[i]=nums[j];
                nums[j]=0;
            }
            i++;
        }
    }
};