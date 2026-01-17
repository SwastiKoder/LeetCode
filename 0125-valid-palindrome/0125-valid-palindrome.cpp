class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return true;

        int i = 0 , j = len - 1;

        while(i < j){
            if(isalnum(s[i]) && isalnum(s[j])){
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
            else if(isalnum(s[i])){
                j--;
            }
            else{
                i++;
            }
        }

        return true;
    }
};