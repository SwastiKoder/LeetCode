class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < word1.length(); i++) {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for (auto ele1 : mp1) {
            if (mp2.find(ele1.first) == mp2.end())
                return false;
        }
        vector<int> v1, v2;
        for (auto ele : mp1) {
            v1.push_back(ele.second);
        }
        for (auto ele : mp2) {
            v2.push_back(ele.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1 == v2)
            return true;
        return false;
    }
};