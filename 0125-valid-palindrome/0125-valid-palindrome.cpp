class Solution {
public:
    bool isPalindrome(string s) {

        int lt = 0, rt = s.length() - 1;

        while (lt <= rt) {
            if (!isalnum(s[lt])) {
                lt++;
                continue;
            }
            if (!isalnum(s[rt])) {
                rt--;
                continue;
            }
            if (tolower(s[lt]) != tolower(s[rt]))
                return false;
            else {
                lt++;
                rt--;
            }
        }
        return true;
    }
};