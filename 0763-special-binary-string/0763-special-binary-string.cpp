class Solution {
public:
    string makeLargestSpecial(string S) {
        if (S.size()==2) return S;

        vector<string>str;
        
        for (int i=0; i<S.size(); i++)
        {
            int j=i;
            int count=0;
            while (i<S.size())
            {
                if (S[i]=='1')
                    count++;
                else
                    count--;                
                if (count==0)
                    break;   
                i++;
            }
            str.push_back("1"+makeLargestSpecial(S.substr(j+1,i-j-1))+"0");
        }
        
        sort(str.begin(),str.end(),greater<string>());
        string res;
        for (auto a:str) res+=a;
        return res;
    }
};