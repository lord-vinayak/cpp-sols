class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        if (ts % 2 == 1 || ts < 2 * cs ||
        ts > cs * 4)
      return {};

    int jumbo = (ts - 2 * cs) / 2;

    return {jumbo, cs - jumbo};
  }
    
};