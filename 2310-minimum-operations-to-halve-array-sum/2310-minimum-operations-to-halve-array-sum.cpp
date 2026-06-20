class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(begin(nums), end(nums), 0.0);
        priority_queue<double> pq;
        for (int num : nums)
            pq.push(num);
        int ans = 0;
        for (double cur = sum; cur > sum / 2; ans++) {
            double num = pq.top();
            pq.pop();
            cur -= num / 2;
            pq.push(num / 2);
        }
        return ans;
    }
};