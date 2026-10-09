class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=nums.size()-1,f=0;
        while(l>f){
            if(nums[(l+f)/2]<target){
                f=((l+f)/2)+1;
            }
            else if(nums[(l+f)/2]>target){
                l=((l+f)/2)-1;
            }
            if(nums[(l+f)/2]==target){
                return ((l+f)/2);
            }
        }
        if(nums[0]>=target){
            return 0;
        }
        if(l==f || l<f){
            if (nums[l]<target){
                return l+1;
            }
            else{
                return l;
            }
        }
        return l;
    }
};