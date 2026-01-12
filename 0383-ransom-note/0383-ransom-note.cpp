class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // // if (ransomNote.length() > magazine.length())
        //     return false;

        unordered_map<char, int> mp;
        for (auto x : magazine) {
            mp[x]++;
        }

        int x = ransomNote.length();

        for (int i = 0; i < x; i++) {
            if (mp.find(ransomNote[i]) != mp.end()) {
                mp[ransomNote[i]]--;
                if (mp[ransomNote[i]] == 0)
                    mp.erase(ransomNote[i]);
            } else
                return false;
        }

        return true;
    }
};