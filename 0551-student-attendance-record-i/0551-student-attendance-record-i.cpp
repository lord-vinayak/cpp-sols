class Solution {
public:
    bool checkRecord(string s) {
	int fa = count(s.begin(), s.end(),'A');
	if(fa<2 && s.find("LLL")==-1 )
	return true;
else return false;
  
    }
};