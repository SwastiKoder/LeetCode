class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto x : nums)
            m[x]++;
        priority_queue<pair<int, int>> pq;
        for (auto ele : m) {
            pq.push({ele.second, ele.first});
        }
        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};