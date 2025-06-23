class Solution {
public:
    bool isUgly(int n) {
      if(n==0)
		return false;
        
	
		int facs[3]={5,3,2};
		for(int fac:facs){
			while (n%fac==0){
				n=n/fac;
			}
		}
        return n == 1;
		
    }
    
};
