class Solution {
public:
    string countAndSay(int n) {
        int x = 2;
        if (n == 1)
            return "1";
        string ans = "1";

        while (x <= n) {
            string str = "";
            int count = 1;
            for (int i = 1; i <= ans.length(); i++) {
                if (i < ans.length() && ans[i] == ans[i - 1]) {
                    count++;
                } else {
                    str += to_string(count);
                    str.push_back(ans[i - 1]);
                    count = 1;
                    
                }
            }
            ans = str;
            x++;
        }
        return ans;
    }
};