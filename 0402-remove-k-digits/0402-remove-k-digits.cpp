class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int count=0;
            
        for (int i=0; i<num.size(); i++)
        {
            if (st.empty()||num[i]>=st.top())
            {
                st.push(num[i]);
            }
            else if (num[i]<st.top())
            {
                while (!st.empty() && num[i]<st.top() && count<k)
                {
                    st.pop();
                    count++;
                }
                st.push(num[i]);
            }
        }
        
        for (int i=count+1; i<=k; i++)
            st.pop();
        
        string result="";
        while (!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        while (result.size()>0 && result.back()=='0')
            result.pop_back();
                
        reverse(result.begin(),result.end());
        if (result=="")
            result="0";
        
        return result;
    }
};