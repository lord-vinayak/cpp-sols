class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0, hi = s.size()-1;
        for(int i=0; i<=(s.size()-1)/2; i++){
            swap(s[i], s[s.size()-1-i]);
        }
        return;
    }
};