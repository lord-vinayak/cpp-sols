class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (ms.count(sc) && ms[sc] != tc) 
                return false;
            if (mt.count(tc) && mt[tc] != sc) 
                return false;

            ms[sc] = tc;
            mt[tc] = sc;
        }
        return true;

    }
};