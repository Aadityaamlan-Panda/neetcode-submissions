class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key)==mp.end()) return "";
        int l =0,r=mp[key].size()-1;
        string ans = "";
        while(l<=r){
            int mid = (l+r)/2;
            auto tmp = mp[key][mid];
            if (tmp.first<=timestamp) {
                ans = tmp.second;
                l = mid+1;
            }
            else r = mid -1;
        }
        return ans;
    }
};
