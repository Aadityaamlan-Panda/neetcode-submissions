class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>hash;
        for (auto num:nums)
        {
            if (hash.count(num)>0) return true;

            hash.insert(num);
        }
        return false;
    }
};