class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int l=0, r=nums.size()-1, lp = 1, rp = 1;
        while(l<nums.size()){
            ans.push_back(lp);
            lp*=nums[l];
            l++;
        }
        while(r>=0){
            ans[r]*=rp;
            rp*=nums[r];
            r--;
        }
        return ans;
    }
};
