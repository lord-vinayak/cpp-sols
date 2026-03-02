class Solution {
public:
    int countGoodSubstrings(string s) {
       int count = 0;

    for (int i = 0; i + 2 < s.length(); ++i) {
      char a = s[i];
      char b = s[i + 1];
      char c = s[i + 2];
      if (a == b || a == c || b == c)
        continue;
      ++count;
    }

    return count;
    }
};