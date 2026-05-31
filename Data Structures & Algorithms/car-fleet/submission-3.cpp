typedef pair<int,int> pii;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pii>cars;
        int n = position.size();
        for (int i=0; i<n; i++){
            cars.push_back({target-position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<double>st;
        for(auto c:cars){
            double t = (double)c.first/c.second;
            if (!st.empty() && t<=st.top()) continue;
            st.push(t);
        }
        return st.size();
    }
};
