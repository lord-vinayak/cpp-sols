class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> res;
        
        for (auto s:words){
            int flag = 0;
            unordered_map<char, char>mp1, mp2;
            int m = s.length();
            for(int i=0; i<m; i++){
                char ch1 = s[i], ch2 = p[i];
                if((mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2)||(mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1))
                {
                    flag=1;
                    break;
                    }
                    mp1[ch1] = ch2; mp2[ch2] = ch1;
            }
                    if(!flag) res.push_back(s);

        }
        return res;
    }
};