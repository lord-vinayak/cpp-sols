class Solution {
public:

bool good (int num){
            bool found = false;
	unordered_set<int> good = {2, 5, 6, 9};
	unordered_set<int> invalid = {3, 4, 7};
	
	while (num) {
		if (invalid.count(num % 10))
			return false;
		found |= good.count(num % 10);
		num /= 10;
	}
	
	return found;
        
}
    int rotatedDigits(int n) {
        int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += good(i);
	return cnt;
    }


};