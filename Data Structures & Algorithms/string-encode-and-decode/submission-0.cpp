
class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for (auto st:strs)
        {
            enc+= to_string(st.length()) + "#" + st;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string>dec;
        int i = 0;
        while(i<s.length())
        {
            int delimpos = s.find("#",i);
            int len = stoi(s.substr(i,delimpos-i));
            string temp = s.substr(delimpos+1,len);
            dec.push_back(temp);

            i = delimpos + len + 1;
        }
        return dec;
    }
};
