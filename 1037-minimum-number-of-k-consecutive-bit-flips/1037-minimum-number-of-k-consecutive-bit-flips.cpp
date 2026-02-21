class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1);

        int flips = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            flips += diff[i];
            if ((nums[i] + flips) % 2 == 1)
                continue;

            if (i + k - 1 >= n)
                return -1;
            flips++;
            count++;
            diff[i + k] -= 1;
        }

        return count;
    }
};