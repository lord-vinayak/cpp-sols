class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string res = "";
        long long n = numerator;
        long long d = denominator;
        if(n<0 ^ d<0) res = res+'-';
        n = abs(n);
        d = abs(d);
        long q = n/d;
        long r = n%d;
        res += to_string(q);
        if (r==0) return res;
        res += '.';
        unordered_map<long, int> mp;
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                int pos = mp[r];
                res.insert(pos, "(");
                res += ')';
                break;
            }
            else{
                mp[r] = res.length();
                r=r*10;
                q = r/d;
                r = r%d;
                res += to_string(q);
            }
        }
        return res;
    }
};