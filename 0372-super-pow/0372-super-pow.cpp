class Solution {
public:
const int M=1337;
int binExp(int a, int b)
{
	long ans=1, p=a;
	while(b)
	{
		if(b&1)
			ans = (ans*p)%M;
		p=(p*p)%M;
		b>>=1;
	}
	return ans%M;
}
    int superPow(int a, vector<int>& b) {
        int bb=1, p=a;
	//std::vector<int> v = {4,3,3,8,5,2};
	for(int i=b.size()-1; i>=0; --i)
	{
		bb = bb*binExp(p,b[i])%M;
		p = binExp(p,10);
	}
	
    return bb;
    }
};