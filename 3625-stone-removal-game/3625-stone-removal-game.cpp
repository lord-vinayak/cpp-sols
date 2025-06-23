class Solution {
public:
    bool canAliceWin(int n) {
        bool win=0;

      for(int i=10;i>0;i--){
           if (n - i < 0){
              return win;
           }
        n -= i;
          win=!win;
      }
        return win;
    }
};