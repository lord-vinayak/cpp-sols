class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>s;
        int curr;
        for (auto x: arr)
        {
            if (s.empty()||s.top()<=x)
            {
                s.push(x);
                curr = x;
            }                
            else
            {
                while (!s.empty() && s.top()>x)
                    s.pop();
                s.push(curr);
            }
        }
        return s.size();
    }
};