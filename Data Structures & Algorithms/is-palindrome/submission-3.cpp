class Solution {
private:
    bool checkAlphanum(char s){
        if (s>='a' && s<='z') return true;
        else if (s>='A' && s<='Z') return true;
        else if (s>='0' && s<='9') return true;
        else return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(l<r){
            while(l<r && !checkAlphanum(s[l])) l++;
            while(l<r && !checkAlphanum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            //to lower helps in case insensitive comparison
            l++; r--; 
        }
        return true;
    }
};
