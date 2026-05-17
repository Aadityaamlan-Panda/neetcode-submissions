class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>M;
        for(auto st:strs)
        {
            string T = st;
            sort(T.begin(),T.end());
            M[T].push_back(st);
        }

        vector<vector<string>>result;
        for (auto i:M)
        result.push_back(i.second);

        return result;
    }
};
