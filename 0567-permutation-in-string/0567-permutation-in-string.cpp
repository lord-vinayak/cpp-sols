class Solution {
public:
    bool checkInclusion(string p, string s) {
        int k = p.size();
        int n = s.size();

        vector<int> pv(26, 0), sv(26, 0);

        if (n < k)
            return false;

        for (int i = 0; i < k; i++) {
            ++pv[p[i] - 'a'];
            ++sv[s[i] - 'a'];
        }

        if(pv==sv) return true;

        else{
            for(int i=k; i<n; i++){
            ++sv[s[i]-'a']; //add next element
            --sv[s[i-k]-'a']; //remove leftmost element

            if(pv==sv) return true;
        }
        return false;
        }
    }
};