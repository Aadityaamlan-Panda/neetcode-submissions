class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        for (auto num:nums){
            if (nums[abs(num)]<0) return abs(num);
            nums[abs(num)] *= -1;
        }
        return -1;
    }
};
