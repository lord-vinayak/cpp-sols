class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0;
        for(char c: s)
            if(c=='1') ones++;
        
        int score = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='0') zeros++;
            else ones--;
            score = max(score, zeros + ones);
        }
        return score;
    }
};