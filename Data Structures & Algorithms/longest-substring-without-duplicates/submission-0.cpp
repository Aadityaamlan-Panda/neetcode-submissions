class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int l=0, r=0, maxLen=0;

        while(r<s.length())
        {
            while(st.count(s[r]))
            {
                st.erase(s[l]); 
                l++;
            }
            st.insert(s[r]);

            maxLen = max(maxLen, r-l+1);

            r++;
        }
        return maxLen;
    }
};
