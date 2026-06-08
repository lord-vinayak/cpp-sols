class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;

        for (auto ch: s)
        {
            if (st.empty() || st.top().first!=ch)            
                st.push({ch, 1});            
            else            
                st.push({ch, st.top().second+1});            

            if (st.top().second==k)
            {
                for (int i=0; i<k; i++)
                    st.pop();
            }
        }

        string res;
        while (!st.empty())
        {
            res.push_back(st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};