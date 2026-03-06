class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), start = 0, res = 0, maxFreq = 0;
        vector<int> freq(26, 0); 

        for (int end = 0; end < n; end++) {
            freq[s[end] - 'A']++;
            
            maxFreq = max(maxFreq, freq[s[end] - 'A']);

            while ((end - start + 1) - maxFreq > k) {
                freq[s[start] - 'A']--; 
                start++;                 
            }

            res = max(res, end - start + 1);
        }
        return res;
    }
};