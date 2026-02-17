class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> v;
        int n = nums.size();

        for(int i = 0; i<k; i++){
            ms.insert(nums[i]);
        }
        v.push_back(*ms.rbegin());

        for(int i=k; i<n; i++){
            int pre = nums[i-k];
            int nex = nums[i];
            ms.erase(ms.find(pre));
            ms.insert(nex);

            v.push_back(*ms.rbegin());

        }
        return v;
    }
};