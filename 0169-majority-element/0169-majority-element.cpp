class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto ele : mp) {
            if (ele.second > nums.size() / 2)
                return ele.first;
        }

        return -1;
    }
};