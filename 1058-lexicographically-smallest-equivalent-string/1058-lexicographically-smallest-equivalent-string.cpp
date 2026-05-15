class Solution {
public:
 int par[26];
    int find(int x)
    {
        if (par[x]!=x)
            par[x] = find(par[x]);
        return par[x];
    }
    
    void Union(int x, int y)
    {
        x = par[x];
        y = par[y];
        if (x<y)
            par[y] = x;
        else
            par[x] = y;
    }
    string smallestEquivalentString(string A, string B, string S) {
        for (int i=0; i<26; i++)
            par[i] = i;
        
        for (int i=0; i<A.size(); i++)
        {
            if (find(A[i]-'a')!=find(B[i]-'a'))
                Union(A[i]-'a', B[i]-'a');
        }
        
        
        string ret;
        for (auto ch: S)
            ret.push_back('a'+find(ch-'a'));
        
        return ret;
    }
};