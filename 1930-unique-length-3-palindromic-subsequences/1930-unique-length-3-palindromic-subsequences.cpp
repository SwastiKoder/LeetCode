class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(27, -1);
        vector<int> last(27, -1);

        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            if (first[x] == -1) {
                first[x] = i;
            }
            last[x] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            if(i != first[x]) continue;
            if (first[x] != -1 && last[x] != -1) {

                unordered_set<int> a;

                for (int j = first[x] + 1; j < last[x]; j++) {
                    a.insert(s[j]);
                }

                count += a.size();
            }
        }

        return count;
    }
};