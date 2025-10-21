class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int ans = 0;
        int x = INT_MIN;
        for (auto ele : mp) {
            if (ele.second > x) {
                x = ele.second;
            }
        }
        for (auto ele : mp) {
            if (ele.second == x)
                ans += ele.second;
        }
        return ans;
    }
};