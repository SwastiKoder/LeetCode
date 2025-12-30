class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n)
            return "";
        int startIdx = -1;
        int ansLen = INT_MAX;

        unordered_map<char, int> need;
        for (auto x : t)
            need[x]++;

        unordered_map<char, int> window;
        int required = need.size();
        int found = 0;

        int left = 0, right = 0;

        while (left < m && right < m) {
            if (need.find(s[right]) != need.end()) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]])
                    found++;
            }
            while (found == required) {
                if (right - left + 1 < ansLen) {
                    startIdx = left;
                    ansLen = right - left + 1;
                }
                if (need.count(s[left])) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]])
                        found--;
                }
                left++;
            }
            right++;
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, ansLen);
    }
};