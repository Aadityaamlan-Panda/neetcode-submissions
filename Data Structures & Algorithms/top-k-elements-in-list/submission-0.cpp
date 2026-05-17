class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>M;
        for (int i = 0; i<n; i++)
        {
            M[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for (auto it = M.begin(); it != M.end(); it++)
        {
            bucket[it->second].push_back(it->first);
        }
        vector<int>result;
        for (int i = n; i>=0; i--)
        {
            if (bucket[i].size()!=0)
            result.insert(result.end(),bucket[i].begin(),bucket[i].end());

            if (result.size()>=k) break;
        }
        return result;
    }
};
