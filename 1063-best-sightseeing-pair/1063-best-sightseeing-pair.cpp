class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mm = 0;
        int n = values.size(), maxScore = 0;
        int maxLeft = values[0] + 0;
        for(int i = 1; i < n; i++) {
            maxScore = max(maxScore, maxLeft + values[i] - i);
            maxLeft = max(maxLeft, values[i] + i);
        }
        return maxScore;
    }
};