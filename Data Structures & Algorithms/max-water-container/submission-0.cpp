class Solution {
private:
    int findArea(int l, int r, vector<int>&heights){
        return min(heights[l],heights[r])*(r-l);
    }
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,maxArea = 0;
        while(l<r){
            maxArea = max(findArea(l,r,heights), maxArea);
            if (heights[l]<heights[r]) l++;
            else r--;
        }
        return maxArea;
    }
};
