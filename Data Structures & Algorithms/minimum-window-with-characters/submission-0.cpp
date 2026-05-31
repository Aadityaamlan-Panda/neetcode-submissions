class Solution {
private:
    bool isValid(unordered_map<char,int>&freq1,
        unordered_map<char,int>&freq2)
        {
            for(auto it:freq1){
                char c = it.first; //extract the character
                if(freq2[c]<freq1[c]) return false;
            } 
            return true;
        }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for (char c:t){
            freq1[c]++;//all map elements are initialised as 0 by default
        }

        int l=0, r=0, minLen=INT_MAX, start=0;
        while(r<s.length()){
            freq2[s[r]]++;
            while (isValid(freq1,freq2)){
                if ((r-l+1)<minLen){
                    minLen = r-l+1;
                    start = l;
                }

                freq2[s[l]]--;
                l++;
            }
            r++;
        }

        if(minLen==INT_MAX) return "";

        return s.substr(start,minLen);
    }
};
