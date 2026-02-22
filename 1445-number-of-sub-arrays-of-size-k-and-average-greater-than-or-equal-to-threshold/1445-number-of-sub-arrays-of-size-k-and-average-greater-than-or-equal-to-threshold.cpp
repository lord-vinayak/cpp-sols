class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        // k is window size
        int n = arr.size();

        int cursum = 0, res = 0, count = 0; 
        //first window
        for(int i = 0; i<k ; i++){
            cursum += arr[i];
        }
        res = cursum/k;
        if (res>=th) count++;

        //remaining windows
        for(int i = k; i<n ; i++){
            int pre = arr[i-k];
            int nex = arr[i];
            cursum -= pre;
            cursum += nex;

            res = cursum/k;
            if(res>=th) count++; 
        }
        return count;
    }
};