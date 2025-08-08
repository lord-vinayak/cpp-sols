class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int lo = 0, hi = people.size()-1, ans = 0;
        while(lo <= hi){
            int sum = people[lo] + people[hi];
            if(sum <= limit){
                ans++;
                lo++;
                hi--;
            }
            else{
                ans++;
                hi--;
            }
        }
        return ans;
    }
};