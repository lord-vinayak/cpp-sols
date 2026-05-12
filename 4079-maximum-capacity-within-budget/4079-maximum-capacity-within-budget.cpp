class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        vector<int> cap, cos; //sorted versions

        vector<pair<int,int>> coscap;
        for (int i = 0; i < n; ++i) 
            coscap.push_back({costs[i], capacity[i]});

        sort(coscap.begin(), coscap.end());

        for (auto i : coscap) {
            cos.push_back(i.first);
            cap.push_back(i.second);
        }

        // max capacity prefix
        vector<int> pref(n, 0);
        pref[0] = cap[0];
        for (int i = 1; i < n; ++i)
         pref[i] = max(pref[i - 1], cap[i]);

        int result = 0;

        // one
        int last = (lower_bound(cos.begin(), cos.end(), budget) - cos.begin()) - 1;
        if (last >= 0)
            result = pref[last];

        // two 
        for (int i = 0; i < n; ++i) {
            int cst = cos[i];
            if (cst >= budget) 
                break;

            
            int limit = budget - cst;
            int j = (lower_bound(cos.begin(), cos.end(), limit) - cos.begin()) - 1;
            j = min(j, i - 1);

            if (j >= 0)
                result = max(result, cap[i] + pref[j]);
        }

        return result;
    }
};