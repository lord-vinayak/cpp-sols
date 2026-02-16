    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            if(n<2) return n;
            int l=0, r=0, mxlen = 0;
            unordered_map<char, int> m;
            while(r<n){
                char ch = s[r];
                if(m.find(ch) != m.end()){
                    mxlen = max(mxlen, r-l);
                    l = max(l, m[ch]+1);
                }
                m[ch] = r;
                r++;
            }
            return max(mxlen, r-l);

        }
    };