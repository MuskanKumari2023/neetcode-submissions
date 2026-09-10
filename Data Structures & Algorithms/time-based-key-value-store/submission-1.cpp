class TimeMap {
public:
    map<string,vector<int>>mp1;
    map<int,string>mp2;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp1[key].push_back(timestamp);
        mp2[timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp1.find(key)==mp1.end())return "";
        auto &v=mp1[key];
        auto it=upper_bound(v.begin(),v.end(),timestamp);
        if(it==v.begin())return "";
        it--;
        return mp2[*it];
    }
};
