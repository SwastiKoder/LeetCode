class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        stringstream ss(s);

        string word;

        while (ss >> word) {
            count = word.length();
        }

        return count;
    }
};