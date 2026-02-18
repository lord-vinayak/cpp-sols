class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int a = words[0].size();
        int sz = words.size();
        //window size = no. of words * size of 1 word
        int k = a * sz;

        vector<int> res;
        if(k>s.size()) return res;

        unordered_map<string, int> mp;
        for(auto &ww:words){
            mp[ww]++;
        }
      
        for (int start=0; start<a; start++){
            unordered_map<string, int> m;
            int i = start;
            int j = i;
            int count = 0;
            while(j<s.size()){
                string str = s.substr(j,a);
                if(mp.find(str)==mp.end()){
                    m.clear();
                    count = 0;
                    j+=a;
                    i=j;
                }
                else if(mp[str]>m[str]){
                    m[str]++;
                    count++;
                    j+=a;
                }
                else if (m[str]==mp[str])
                {
                    m[s.substr(i,a)]--;
                    i+=a;
                    count--;
                }
                
                if (count==sz)
                {
                    res.push_back(i);
                    m[s.substr(i,a)]--;
                    i+=a;
                    count--;                    
                }                                     
            }

        }
        return res;
    }
};