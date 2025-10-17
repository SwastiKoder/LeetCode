class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> p(
            cmp);

        for (auto x : m) {
            p.push({x.second, x.first});
        }
        vector<int> ans;
        while (p.size()) {
            int x = p.top().first;
            int y = p.top().second;
            while (x > 0) {
                ans.push_back(y);
                x--;
            }
            p.pop();
        }
        return ans;
    }
};