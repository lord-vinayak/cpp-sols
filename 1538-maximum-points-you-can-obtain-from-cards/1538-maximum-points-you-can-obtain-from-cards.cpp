class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size(), r = n - k;

        int res =
            accumulate(arr.begin() + r, arr.end(), 0);

        int sum = res;
        for (int l = 0; r < n; l++, r++) {
            sum += arr[l] - arr[r];
            res = max(res, sum);
        }

        return res;
    }
};