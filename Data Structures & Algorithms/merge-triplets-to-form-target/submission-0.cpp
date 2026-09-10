class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false,b=false,c=false;
        for(auto &x:triplets){
            if(x[0]>target[0] or x[1]>target[1] or x[2]>target[2])continue;
            if(x[0]==target[0])a=true;
            if(x[1]==target[1])b=true;
            if(x[2]==target[2])c=true;
            if(a and b and c)return true;
        }
        return false;
    }
};
