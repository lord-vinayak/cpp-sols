class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if(!nums.size())return ans;
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
         for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                ans.push_back(bucket[i][j]);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};