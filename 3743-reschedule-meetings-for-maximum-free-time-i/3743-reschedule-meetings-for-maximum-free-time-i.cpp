class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start,
                    vector<int>& end) {
        vector<int> fre; 
        
        fre.push_back(start[0]);

        for (int i = 1; i < start.size(); i++)
            fre.push_back(start[i] - end[i - 1]);

        fre.push_back(eventTime - end[end.size()-1]);
        
        int currsum =0, res=0;
        for(int i=0; i<k+1; i++){
            currsum += fre[i];
        }
        res = currsum;

        for(int i = k+1; i<fre.size(); i++){
            int pre = fre[i-(k+1)];
            int nex = fre[i];
            currsum += nex;
            currsum -= pre;

            res = max(currsum, res);
        }
        return res;
    }
};