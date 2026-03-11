class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //longest subarray with k = 2 (atmost 2 different elements)
        unordered_map<int, int> mp; // to store types of fruits
        int start = 0, end = 0, res = 0;
        for (end = 0; end < fruits.size(); end++) {
            mp[fruits[end]]++;

            while (mp.size() > 2) { //if there are more than 2 types of fruits
                mp[fruits[start]]--;
                if (mp[fruits[start]] == 0) {
                    mp.erase(fruits[start]);
                }
                start++;
            }

            res = max(res, end - start + 1);
        }
        return res;
    }
};