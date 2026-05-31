typedef pair<int,int> pii;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pii>st;
        int maxArea = 0;
        int n = heights.size();
        for (int i=0; i<n; i++){
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();

                int width = i - index;
                maxArea = max(maxArea, height * width);

                start = index;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            auto [index,height] = st.top();
            st.pop();

            int width = n-index;
            maxArea = max(maxArea, height*width);
        }
        return maxArea;
    }
};
