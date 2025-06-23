class Solution {
public:
int cc = 0;
int find_set(int a, vector<int> &parent){
    if(parent[a]==0) {
        cc++;
        parent[a]=a;
    }
    return parent[a] ==a? a:(parent[a]= find_set(parent[a], parent));
}
void union_set(int a, int b, vector<int> &parent){
     a = find_set(a, parent);

     b = find_set(b, parent);
     if(a!=b){
        parent[b] = a;
        cc--;
     }
}
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(20003, 0);
        for(auto stone:stones){
            union_set(stone[0]+1, stone[1]+10002, parent);
        }
        return stones.size()-cc;
    }
};