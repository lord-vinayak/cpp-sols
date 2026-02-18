class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int n = s.size();

        vector<int> pv(26,0), sv(26,0), res;

        if(n<k) return res;

        for(int i=0; i<k; i++){
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv==sv) res.push_back(0);

        for(int i=k; i<n; i++){
            ++sv[s[i]-'a']; //add next element
            --sv[s[i-k]-'a']; //remove leftmost element

            if(pv==sv) res.push_back(i-k+1);
        }
        return res;
    }
};