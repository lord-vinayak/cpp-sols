class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minn = INT_MAX;
        for(int n:nums) {
            if(n%2!=0) n = n*2;
            pq.push(n);
            minn = min(minn, n);            
        }
        int res = INT_MAX;
        while(pq.top()%2 ==0){
            //even no at top then halve it

            res = min(res, pq.top()-minn);
            minn = min(minn, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }

        return min(res, pq.top()-minn);

        // 20 5 4 3 1 ---> pq

        
    }
};