typedef pair<int,int> pii;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pii>st;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for (int i=0; i<n; i++){
            while(!st.empty() && st.top().first<temperatures[i]){
                ans[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
