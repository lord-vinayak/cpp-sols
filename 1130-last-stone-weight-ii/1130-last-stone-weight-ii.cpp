class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for (int stone : stones) {
            total = total + stone;
        }
        vector<int> arr = stones;
        int sum = total;
        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < sum + 1; ++j) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // vector<int> v;
        // for(int i=0; i<total/2;i++){
        // 	if(dp[n][i]==true) v.pb(i);
        // }
        // int m = INT_MAX;
        // for(int i=0; i<v.size(); i++)
        // 	m = min(m,total-2*v[i]);
        // cout<<m;
        int minWeight = INT_MAX;

        for (int i = total / 2; i >= 0; i--) {
            if (dp[n][i] == true) {
                minWeight = total - (2 * i);
                break;
            }
        }
        return minWeight;
    }
};