class Solution {
public:
long long M = 1e9+7;
    int countGoodNumbers(long long n) {
        long long a = n/2;
        long long b = n-a;

        return poww(5,b)*poww(4,a)%M;
    }

    long long poww(long long x, long long k)
    {
        if (k==0) return 1;
        long long y = poww(x, k/2);

        if (k%2==0)        
            return y*y%M;
        else
            return y*y%M*x%M;        
    }
};