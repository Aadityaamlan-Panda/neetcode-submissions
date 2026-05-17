class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string c:strs)
        {
            s+=c;
            s+=".";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> str;
        int i=0;
        while(i!=s.length())
        {
            string a = "";
            while (s[i]!='.') {
                a+=s[i];
                i++;
            }
            str.push_back(a);
            i++;
        }
        return str;

    }
};
