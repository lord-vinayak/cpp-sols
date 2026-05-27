class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) 
    {
        int res = 0;
        int n = ans.size();
        
        int flip = 0;        
        int j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (ans[j]=='T' || flip<k))
            {
                if (ans[j]!='T')
                    flip++;
                j++;                    
            }
            res = max(res, j-i);
            if (ans[i]=='F')
                flip--;
        }
        
        flip = 0;        
        j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (ans[j]=='F' || flip<k))
            {
                if (ans[j]!='F')
                    flip++;
                j++;                    
            }
            res = max(res, j-i);
            if (ans[i]=='T')
                flip--;
        }
        
        return res;
    }
};