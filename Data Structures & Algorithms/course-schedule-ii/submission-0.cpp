class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>g(numCourses);
        vector<int>indeg(numCourses);
        for(auto &x:prerequisites){
            g[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto v:g[cur]){
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        if(topo.size()==numCourses)return topo;
        return {};
    }
};
