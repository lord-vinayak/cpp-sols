class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 1, len = 1;
        while(i < n){
            while(j < n && chars[j] == chars[i])
                j++;
            int count = j - i;
            if(i > 0){
                chars[len] = chars[i];
                len++;
            }
            if(count > 1){  
                for(char c : to_string(count)){
                    chars[len] = c;
                    len++;
                }
            }
            i = j; 
        }
        return len;
    }
};