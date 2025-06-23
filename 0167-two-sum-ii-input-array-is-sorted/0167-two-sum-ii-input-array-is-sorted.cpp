class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lt=0, rt=numbers.size()-1;
        while(numbers[lt]+numbers[rt]!=target){
            if(numbers[lt]+numbers[rt]<target) lt++;
            else rt--;
        }
        return vector<int>({lt+1,rt+1});
    }
};