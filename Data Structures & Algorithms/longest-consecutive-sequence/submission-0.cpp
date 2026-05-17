class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlength = 0;
        unordered_set numSet(nums.begin(),nums.end());
        for (int num:numSet)
        {
            if (numSet.count(num-1)==0)
            {
                int length = 1;
                while (numSet.count(num+length)!=0)
                length++;
                maxlength = max(length,maxlength);
            }
        }
        return maxlength;
    }
};
