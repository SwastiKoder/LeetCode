class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> mp;
        int left = 0;
        int maxl = 1;

        for (int right = 0; right < s.length(); right++) {

            if (mp.find(s[right]) != mp.end())
                left = max(left, mp[s[right]] + 1);

            mp[s[right]] = right;

            maxl = max(maxl, right - left + 1);
        }

        return maxl;
    }
};