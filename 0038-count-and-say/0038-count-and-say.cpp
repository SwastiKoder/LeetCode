class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string str = countAndSay(
            n - 1); // for calling the nesxt function until it reaches n = 1
        string ztr = "";
        char ch = str[0];
        int freq = 1;
        for (int i = 1; i < str.length();
             i++) { // a string question more than a recursion question
            if (ch == str[i]) {
                freq++;
            } else {
                ztr = ztr + (to_string(freq) + ch);
                freq = 1;
                ch = str[i];
            }
        }
          ztr = ztr + (to_string(freq) + ch); // for last character cuz loop breaks after rreaching the last number
        return ztr;
    }
};