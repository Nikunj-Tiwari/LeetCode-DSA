class Solution {
public:
    int maxArea(vector<int>& height) {
        int m=0,n=height.size()-1;
        double max_area;
        if(height[m]<height[n]){
            max_area=height[m]*n; 
        }
        else{
            max_area=height[n]*n;
        }
        for(int i =0 ;i<height.size();i++){
            if(height[m]<height[n]){
                if(height[m]*(height.size()-(i+1))>max_area){
                    max_area=height[m]*(height.size()-(i+1));
                }
                m++;
            }
            else{
                if((height[n]*(height.size()-(i+1)))>max_area){
                    max_area=height[n]*(height.size()-(i+1));
                }
                n--;
            }
            }
            return max_area;
        }
};