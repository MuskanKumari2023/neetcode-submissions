class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int tail=0,head=-1;
        int ans=0;
        while(tail<n){
            while(head+1<n and mp[s[head+1]]==0){
                head++;
                mp[s[head]]++;
            }
            ans=max(ans,head-tail+1);
            if(head>=tail){
                mp[s[tail]]--;
                tail++;
            }
            else
            {
                tail++;
                head=tail-1;
            }
        }
        return ans;
    }
};
