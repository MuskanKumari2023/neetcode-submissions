class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        int left=0,right=n-1;
        int cur=0;
        while(left<right){
            cur=min(heights[left],heights[right])*(right-left);
            maxi=max(maxi,cur);
            if(heights[left]<heights[right])left++;
            else right--;
        }
        return maxi;
    }
};
