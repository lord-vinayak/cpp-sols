class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s:stones){
            pq.push(s);
        }
        while(pq.size()>1){
            int fs = pq.top();
            pq.pop();
            int ss = pq.top();
            pq.pop();
            if(fs==ss) continue;
            else pq.push(abs(ss-fs));
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};