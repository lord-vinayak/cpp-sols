class Solution {
public:
    string removeDuplicateLetters(string s) {
        string text = s;
        string str;
        unordered_map<char,int>mp;
        for (auto ch: text)
            mp[ch]++;
        unordered_set<char>vis;
        
        for (auto ch: text)
        {
            if (vis.find(ch)!=vis.end())
            {
                mp[ch]--;
            }
            else
            {
                while (str.size()>0  && str.back()>ch && mp[str.back()]>0)
                {
                    vis.erase(str.back());
                    str.pop_back();
                }
                str.push_back(ch);
                mp[ch]--;
                vis.insert(ch);
            }
        }
        
        return str;
    }
};