class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int depth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='*')depth++;
            else depth--;
            if(depth<0)return false;
        }
        depth=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' or s[i]=='*')depth++;
            else depth--;
            if(depth<0)return false;
        }
        return true;
    }
};
