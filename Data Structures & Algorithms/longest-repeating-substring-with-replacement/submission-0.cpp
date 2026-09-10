class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.size();
       int ans=1;
       for(int i=0;i<26;i++){
        int tail=0,head=-1;
        int cnt=0;
        while(tail<n){
            while((head+1)<n and ((s[head+1]==i+'A') or (s[head+1]!=i+'A' and cnt<k))){
                head++;
                if(s[head]!=(i+'A'))cnt++;
            }
            ans=max(ans,head-tail+1);
            if(head>=tail){
                if(s[tail]!=(i+'A'))cnt--;
                tail++;
            }
            else
            {
                tail++;
                head=tail-1;
            }
        }
       }
       return ans;
    }
};
