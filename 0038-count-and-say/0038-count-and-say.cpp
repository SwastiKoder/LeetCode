class Solution {
public:
    string speak(string prev) {
        int count = 1;
        string ans = "";
        for (int i = 1; i <= prev.size(); i++) {
            if (i < prev.size() && prev[i] == prev[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += prev[i - 1];
                count = 1;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        return speak(prev);
    }
};