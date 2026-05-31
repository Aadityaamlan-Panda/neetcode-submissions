class Solution {
private:
    bool isOpen(char c){
        if (c=='{'|| c=='(' || c=='[') return true;
        return false;
    }
    bool checkComp(char c, char d){
        if (c=='}') {
            if (d=='{') return true;
            else return false;
        }
        if (c==']') {
            if (d=='[') return true;
            else return false;
        }
        if (c==')') {
            if (d=='(') return true;
            else return false;
        }
        return false;
    }
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if (isOpen(c)) st.push(c);
            else {
                if (st.empty()) return false;
                if (!checkComp(c,st.top())) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
