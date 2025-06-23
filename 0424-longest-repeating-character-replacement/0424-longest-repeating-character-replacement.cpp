class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int lt=0, rt = 0;
        int maxchar = 0;
        int n = s.length();
        int res = 0;
        for(rt=0; rt<n; rt++){
            freq[s[rt]-'A']++;
            maxchar = max(maxchar, freq[s[rt]-'A']);

            int change = (rt-lt+1)-maxchar;
            if(change>k) {
                freq[s[lt]-'A']--;
                lt++;
            }
            res = max(res, rt-lt+1);
        }
        return res;
    }
};