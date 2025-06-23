class Solution {
public:
vector<int> parent, size;
    int find_set(int v){
        if(v==parent[v])
        return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& act) {
         int n = act.size();
        parent.resize(n+1,0);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
       
        unordered_map<string, int> mailID;
        for(int i =0 ; i<n; i++){
            for(int j=1 ; j<act[i].size(); j++){
                string mail = act[i][j];
                if(mailID.find(mail)==mailID.end())
                mailID[mail] = i;
                else 
                union_set(i, mailID[mail]);
            }
        }
        vector<vector<string>> merged(n);
        for(auto it:mailID){
            string mail = it.first;
            int node = find_set(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(act[i][0]);
            for(auto it:merged[i])
            temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};