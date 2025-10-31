class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto ele : mp) {
            if (ele.second == 2)
                ans.push_back(ele.first);
        }
        return ans;
    }
};