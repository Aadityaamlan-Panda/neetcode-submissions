class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length()>s2.length()) return false;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char c:s1) freq1[c-'a']++;

        int windowSize = s1.length();

        int l =0, r = 0;
        while (r<s2.length()){
            freq2[s2[r]-'a']++;
            if (r-l+1>windowSize)
            {
                freq2[s2[l]-'a']--;
                l++;
            }
            if (freq1==freq2) return true;
            r++;
        }
        return false;
    }
};
