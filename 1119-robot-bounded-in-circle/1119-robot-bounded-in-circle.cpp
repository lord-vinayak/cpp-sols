class Solution {
public:
    bool isRobotBounded(string s) {
        vector<vector<int>> dire = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0, x = 0, y = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='G'){
                x+=dire[dir][0];
                y+=dire[dir][1];
            } else{
                dir = s[i]=='L'?(dir-1+4)%4:(dir+1)%4;
            }
        }
        return (dir!=0) || (x==0 && y==0);
    }
};