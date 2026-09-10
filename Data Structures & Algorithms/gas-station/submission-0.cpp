class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_gas=0,tot_cost=0;
        for(auto x:gas)tot_gas+=x;
        for(auto x:cost)tot_cost+=x;
        if(tot_cost>tot_gas)return -1;
        
        int cur_tank=0;
        int start=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            cur_tank+=(gas[i]-cost[i]);
            if(cur_tank<0){
                start=i+1;
                cur_tank=0;
            }
        }
        return start;
    }
};
