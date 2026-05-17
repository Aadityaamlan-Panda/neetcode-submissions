class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>out(n,1);
        int prefix = 1, suffix = 1;
        int last = n-1;
        for (int i=0;i<n;i++)
        {
            out[i]*=prefix;
            prefix*=nums[i];
            out[last-i]*=suffix;
            suffix*=nums[last-i];
        }
        return out;
    }
};
