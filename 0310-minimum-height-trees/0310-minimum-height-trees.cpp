class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==0) return {};
        if (n==1) return {0};
        vector<int> res, indeg;
        vector<vector<int>> graph(n);

        indeg.resize(n,0);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==1) q.push(i);
        }
        while(!q.empty()){
            res.clear();
            int s = q.size();
            for(int i=0; i<s; i++){
                int f = q.front();
                q.pop();
                res.push_back(f);
                for(auto j:graph[f]){
                    indeg[j]--;
                    if(indeg[j]==1) q.push(j);
                }    
            }
        }
        return res;
    }
};