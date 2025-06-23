class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> out = prices;
	int n = prices.size();
	for(int i = 0 ; i<n; i++){
		for(int j = i; j<n ; j++){
			if(prices[j]<=prices[i] && j>i){
				out[i] = min(out[i], out[i]-prices[j]);
				break;			}
		}
	}
	return out;
	}
    
};