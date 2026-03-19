class Solution {
public:
    vector<string>result;
    vector<string> letterCombinations(string di) {
        if(di=="")  return {};
        helper(di,0,"");
        return result; 
    }
    
    void helper(string di,int idx,string curr)
    {
         vector<string>v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};   

        if(idx==di.length()) //base case
        {
            result.push_back(curr);
            return;
        }
        string s=v[di[idx]-'0'];
        for(int i=0;i<s.length();i++)
        {
            helper(di,idx+1,curr+s[i]);
        }
    }
};