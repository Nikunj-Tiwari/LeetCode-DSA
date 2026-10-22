class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sl=-1,l=-1;
        for(int i=0; i<nums.size(); i++){
        if(nums[i]>l){
            sl = l;
            l =nums[i];
        }
        else if(nums[i]>sl){
            sl =nums[i];
        }
    }
    return ((l - 1) * (sl - 1));
    }
};