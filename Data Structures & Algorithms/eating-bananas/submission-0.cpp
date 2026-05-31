class Solution {
private:
    bool check(int k, vector<int>&piles, int h){
        long long hours = 0;
        for (int pile:piles){
            hours += ceil((double)pile/k);
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = *max_element(piles.begin(),piles.end());
        int ans =r;
        while(l<=r) {
            int mid = (l+r)/2;
            if (check(mid,piles,h)){
                ans = mid;
                r=mid-1;
            }
            else l= mid+1;
        }
        return ans;
    }
};
