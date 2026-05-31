class Solution {
private:
    bool isSign(string c){
        if (c=="*"||c=="/"||c == "+"||c=="-") return true;
        return false;
    }
    int signImp(string c, int a, int b){
        if (c=="*") return a*b;
        if (c=="+") return a+b;
        if (c=="/") return a/b;
        if (c=="-") return a-b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (string t:tokens){
            if (isSign(t)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(signImp(t,a,b));
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};
