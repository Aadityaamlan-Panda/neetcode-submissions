class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0); //initialise bucket with 0s
        int l=0, r=0, maxf=0, ans=0;
        while(r<s.length()){
            count[s[r]-'A']++;//increase count inside buckets
            maxf = max(maxf,count[s[r]-'A']);//max frequency update
            while((r-l+1)-maxf>k){ //If replacements > k,  adjust from left
                count[s[l]-'A']--;
                l++;
            }
            ans = max(ans,r-l+1);//max after replacment adjustment
            r++;
        }
        return ans;
    }
};