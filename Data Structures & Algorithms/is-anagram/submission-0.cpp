class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>f(26,0);
        for (char ch:s)
        {
            f[ch-'a']++;
        }
        for (char ch:t)
        {
            f[ch-'a']--;
        }
        for (auto i:f)
        {
            if (i!=0) return false;
        }
        return true;
    }
};
