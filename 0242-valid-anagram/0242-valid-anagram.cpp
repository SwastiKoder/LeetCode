class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (int i = 0; i < s.length(); i++) {
            m1[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            m2[t[i]]++;
        }
        for (auto ele : m1) {
            char ch1 = ele.first;
            int f1 = ele.second;
            if (m2.find(ch1) != m2.end()) {
                int f2 = m2[ch1];
                if (f1 != f2)
                    return false;
            }
            else return false;
        }
        return true;
    }
};