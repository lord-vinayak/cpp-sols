class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int> indeg(n, 0);

        for (auto r : roads) {
            indeg[r[0]]++;
            indeg[r[1]]++;
        }

        priority_queue<pair<int, int>> pq; 
        // max heap < indeg,node index>

        for (int i = 0; i < n; i++)
            pq.push({indeg[i], i});

        int value=n;
        while(!pq.empty()){
            auto p =pq.top(); 
            pq.pop();
            
            indeg[p.second]=value--;
        }
        
        long long res=0;
        
        for(auto r: roads){
            res+= indeg[r[0]];
            res+=indeg[r[1]];
        }
        return res;
    }
};