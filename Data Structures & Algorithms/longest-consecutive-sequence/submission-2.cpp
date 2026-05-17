class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest = 0;
        for (int num:nums)
        {
            if (!st.count(num-1))
            {
                int currNum = num;
                int currLen = 1;
                while(st.count(currNum+1))
                {
                    currNum++;
                    currLen++;
                }
                longest = max(longest, currLen);
            }
        }
        return longest; 
    }
};
