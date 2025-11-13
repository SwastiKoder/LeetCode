class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto ele : mp) {
            if (ele.second == 2) {
                ans[0] = ele.first;
                break;
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end()) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};