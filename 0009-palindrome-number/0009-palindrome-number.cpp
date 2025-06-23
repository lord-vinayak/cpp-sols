class Solution {
public:
    bool isPalindrome(int x) {
        int r=0,num;
        if(x<0) num=-1LL*x;
        else num=x;      
        while(num){
         if (r>INT_MAX/10 || r<INT_MIN/10) return 0; 
         r=r*10+num%10; 
         num=num/10;     
        } 
        if(r==x) return true;
        else return false;
    }
};