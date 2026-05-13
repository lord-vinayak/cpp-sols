class Solution {
public:
    int superEggDrop(int K, int N) {
        auto arr = vector<vector<int>>(K+1,vector<int>(N+1,0));
        
        int m = 0;
        
        while (arr[K][m]<N)
        {
            m++;
            for (int k=1; k<=K; k++)
                arr[k][m] = arr[k-1][m-1]+1+arr[k][m-1];
        }
        return m;
    }
};